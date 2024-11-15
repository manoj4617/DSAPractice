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
    virtual int save(int n) = 0;
    virtual float save(int n, float k) = 0;
};

class Derived : public Base {
    public:
    Derived() {
        cout << "Derived class constructor!!\n";
    }

    ~Derived() {
        cout << "Derived class destructor!!\n";
    }

    int save(int n) override {
        cout << "int overriding\n";
        return 0;
    }
    float save(int n, float k) override{
        cout << "float overriding\n";
        return 1.1F;
    }
};

int main(){
    Base* base = new Derived;
    base->save(9, 1.89);
    delete base;
}

