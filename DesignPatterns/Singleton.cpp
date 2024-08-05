#include <chrono>
#include <iostream>
#include <string>
#include <thread>

class Singleton {
    protected:
    Singleton(const std::string value) : _value(value){}
    static Singleton* _instance;
    std::string _value;

    public:
    Singleton(Singleton & other) = delete;
    void operator=(Singleton &) = delete;
    static Singleton* getInstance(const std::string &value);

    std::string value(){
        return _value;
    }
};

Singleton* Singleton::_instance = nullptr;

Singleton* Singleton::getInstance(const std::string &value){\
    if(_instance == nullptr){
        _instance =  new Singleton(value);
    }
    return _instance;
}

void ThreadOne(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Singleton* singleton = Singleton::getInstance("thread_one");
    std::cout << singleton->value() << "\n";
}

void ThreadTwo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Singleton* singleton = Singleton::getInstance("thread_two");
    std::cout << singleton->value() << "\n";
}

int main(){
    std::thread t1(ThreadOne);
    std::thread t2(ThreadTwo);
    t1.join();
    t2.join();

    return 0;
}