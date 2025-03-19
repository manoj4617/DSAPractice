#include <iostream>
#include <atomic>
#include <stdatomic.h>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

template <typename T>
class LockFreeStack {
    private:
        struct Node{
            T data;
            Node* next;
            Node(const T& val) : data(val), next(nullptr){}
        };
        atomic<Node*> head;

    public:
        void push(T val){
            Node* new_node = new Node(val);
            new_node->next = head.load(memory_order_relaxed);
            while(!head.compare_exchange_weak(new_node->next, new_node,
                                                memory_order_release, memory_order_relaxed));
            std::cout << "Pushed: " << val << "\n";
        }

        T pop(){
            Node* old_head = head.load(memory_order_acquire);
            while(old_head){
                if(head.compare_exchange_weak(old_head, old_head->next,
                                                memory_order_acquire, memory_order_relaxed)){
                    T value = old_head->data;
                    delete old_head;
                    cout << "Popped: " << value << endl;
                    return value;
                }    
            }
            
        }
};

LockFreeStack<int> st;

void push_worker(int thread_id, int num_pushed){
    for(int i=0;i<num_pushed;++i){
        st.push(thread_id * 100 + i);
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void pop_worker(int thread_id, int num_pops){
    for(int i=0;i<num_pops;++i){
        int val = st.pop();
        this_thread::sleep_for(chrono::milliseconds(15));
        if(val != -1){
            cout << "Thread " << thread_id << " popped: " << val << endl;
        }
    }
}

int main(){
    const int num_threads = 4;
    const int num_operations = 10;

    vector<thread> threads;
    for(int i=0;i<num_operations;++i){
        threads.emplace_back(push_worker, i, num_operations);
    }

    for(auto &t : threads){
        t.join();
    }

    threads.clear();

    for(int i=0;i<num_operations;++i){
        threads.emplace_back(pop_worker, i, num_operations);
    }
    
    for(auto &t : threads){
        t.join();
    }

    return 0;
}