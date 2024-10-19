#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;

std::mutex mt;

void increamentCounter(){
    for(int i=0;i<10;i++){
        std::lock_guard<std::mutex> lock(mt);
        std::cout << "Thread: " << std::this_thread::get_id() << " executing\n";
        ++counter;
    }
}

int main(){
    std::thread t1(increamentCounter);
    std::thread t2(increamentCounter);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << "\n";
    return 0;
}