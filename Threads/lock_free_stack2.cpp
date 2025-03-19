#include <atomic>
#include <iostream>
#include <memory>


template <typename T> class LockFreeStack {
private:
  struct Node {
    std::shared_ptr<T> data;
    Node *next;
    Node(const T &val) : data(std::make_shared<T>(val)), next(nullptr) {}
  };

  std::atomic<Node *> head;

public:
  LockFreeStack() : head(nullptr) {}

  void push(const T &value) {
    Node *new_node = new Node(value);
    Node *old_head = head.load(std::memory_order_relaxed);
    do {
      new_node->next = old_head;
    } while (!head.compare_exchange_weak(old_head, new_node,
                                         std::memory_order_release,
                                         std::memory_order_relaxed));
  }

  std::shared_ptr<T> pop() {
    Node *old_head = head.load(std::memory_order_acquire);
    while (old_head != nullptr) {
      Node *next_head = old_head->next;
      if (head.compare_exchange_weak(old_head, next_head,
                                     std::memory_order_acq_rel,
                                     std::memory_order_relaxed)) {
        return old_head->data;
      }
      old_head = head.load(std::memory_order_acquire);
    }
    return nullptr;
  }

  bool empty() const { return head.load(std::memory_order_acquire) == nullptr; }
};

int main() {
  LockFreeStack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);

  std::cout << "Popping from stack:" << std::endl;
  std::shared_ptr<int> value;
  while ((value = stack.pop())) {
    std::cout << *value << std::endl;
  }

  std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No")
            << std::endl;

  return 0;
}