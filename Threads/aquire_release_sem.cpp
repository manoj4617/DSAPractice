#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <atomic>

std::vector<int> sharedData;
std::atomic<bool> dataProduced(false);
std::atomic<bool> dataConsumed(false);

void dataProducer(){
    sharedData = {1,0,3};
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    dataProduced.store(true, std::memory_order_release);
    std::cout << "loaded data in shared mem\n";
}

void deliverBoy(){
    while(!dataProduced.load(std::memory_order_acquire)){
        std::cout << "\twaiting for data to load from producer\n";
    }
    std::cout << "Handed data to be consumed\n";
    dataConsumed.store(true, std::memory_order_release);
}

void dataConsumer(){
    while(!dataConsumed.load(std::memory_order_acquire)){
        std::cout << "\twaiting for consuming\n";
    }
    std::cout << "Consumed data\n";
    sharedData[1] = 2;
}

int main(){

    std::thread t1(dataProducer);
    std::thread t2(dataConsumer);
    std::thread t3(deliverBoy);
    
    t1.join();
    t2.join();
    t3.join();

    for(auto& v : sharedData){
        std::cout << v << " ";
    }
    return 0;
}