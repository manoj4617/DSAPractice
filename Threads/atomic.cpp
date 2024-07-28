#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter(0);  // This is our special Lego brick

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter++;  // This operation is atomic
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;  // Will always be 2000
    return 0;
}