#include<iostream>
#include<thread>

void hello(){
    std::cout<<"Hello this is my first thread program"<<std::endl;
}

int main(){
    std::thread t(hello);
    t.join();
}