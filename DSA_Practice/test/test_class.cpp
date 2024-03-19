#include<iostream>

using namespace std;

class A{
    public:
        A(){
            cout << "A constructor"<<endl;
        }
        ~A(){
            cout << "A destructor"<<endl;
        }
};

class B : A{
        public:
        B(){
            cout << "B constructor" << endl;
        }
        ~B(){
            cout << "B destructor"<<endl;
        }
};

int main(){
    B b;
    A a;

    return 0;
}