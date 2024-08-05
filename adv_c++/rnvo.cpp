#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor" << std::endl;
    }
    MyClass(const MyClass&) {
        std::cout << "MyClass Copy Constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }
};

MyClass createObject() {
    MyClass obj;
    return obj;
}

int main() {
    MyClass myObj = createObject();
    return 0;
}
