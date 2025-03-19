#include <iostream>
#include <thread>

void task() {
    std::cout << "Thread ID: " << std::this_thread::get_id() << "\n";
}

int main() {
    std::thread t1(task);  // Create thread
    std::thread t2(task);  // Create thread

    t1.join();  // Wait for thread to finish
    t2.join();
}