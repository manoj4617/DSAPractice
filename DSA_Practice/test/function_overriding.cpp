#include<iostream>

using namespace std;

class Base{
    public:
        virtual void Print(){
            cout<< "This is base class"<<endl;
        }

        void show(){
            cout << "showing the base class" << endl;
        }
};

class Child : public Base{
    public:
        void Print(){
            cout << "This is child class" << endl;
        }

        void show()
        {
            cout << "show derived class" << endl;
        }
};

int main(){
    Base *base;
    Child child;
    base = &child;
   
    base->Print();

    base->show();
    return 0;
}