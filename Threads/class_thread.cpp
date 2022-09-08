#include<iostream>
#include<thread>

class new_thread{
    public:
     void operator() () const{  
        std::cout<<"Doing something"<<std::endl;
     }
     void do_something_else(){
        std::cout<<"Doing something else"<<std::endl;
     }
};

int main(){
    
    new_thread t;
    std::thread background_thread{new_thread()}; //declaring std::thread as a variable

}