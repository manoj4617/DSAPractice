#include <iostream>
#include <thread>
#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
std::atomic<bool> done(false);

void producer(int count){
    for(int i=0;i<count;++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock<std::mutex> lock(mtx);
        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one();
    }
    done.store(true,std::memory_order_seq_cst);
    cv.notify_all();
}

void consumer(){
    while(!done.load(std::memory_order_seq_cst) || !buffer.empty()){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,
                [] {
                    return !buffer.empty() || done.load(std::memory_order_seq_cst);
                });
        while(!buffer.empty()){
            int item = buffer.front();
            buffer.pop();
            std::cout << "Consumed: " << item << std::endl;
        }

    }
}

int main(){
    std::thread t1(producer, 1000);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}