#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void thread1(){
    std::lock(mtx1,mtx2);
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::cout << "\nThread: " << std::this_thread::get_id() << " holding lock1 \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
}



void thread2(){
    std::lock(mtx1,mtx2);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    std::cout << "\nThread: " << std::this_thread::get_id() << " holding lock2 \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
}

int main(){
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}