#include <iostream>
#include <memory>

class A {
public:
    void show() { std::cout << "A is alive\n"; }
};

int main() {
    std::shared_ptr<A> sp = std::make_shared<A>();
    std::weak_ptr<A> wp = sp;  // weak_ptr does not increase ref count

    if (auto temp = wp.lock()) {  // Convert weak_ptr to shared_ptr
        temp->show();
    } else {
        std::cout << "Object no longer exists\n";
    }

    sp.reset();  // Free the object

    if (wp.expired()) {
        std::cout << "Pointer is expired\n";
    }

    return 0;
}