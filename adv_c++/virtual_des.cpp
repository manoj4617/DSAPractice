#include <iostream>

using namespace std;

class Base {
    public:
    Base() {
        cout << "Base class constructor!!\n";
    }

    // A virtual destructor is needed in the base class in this case because when
    // deleting an object of a derived class through a base class pointer, the
    // destructor of the derived class needs to be called. If the destructor of the
    // base class is not declared as virtual, only the destructor of the base class
    // will be called, which may not be what we want. By declaring the destructor
    // as virtual, the destructor of the derived class will be called as well.
    virtual ~Base() {
        cout << "Base class destructor!!\n";
    }
};

class Derived : public Base {
    public:
    Derived() {
        cout << "Derived class constructor!!\n";
    }

    ~Derived() {
        cout << "Derived class destructor!!\n";
    }
};

int main(){
    Derived* base = new Derived;
    delete base;
}

