#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

#define N 30
std::condition_variable cv;
std::mutex mtx;
int counter = 1;

void print_odd(){
    // This function prints the odd numbers from 1 to N
    while(counter <= N){
        // Create a lock that can be used to wait for the condition variable
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until the condition variable is notified that the counter is odd
        cv.wait(lock, [] { return counter % 2 == 1;});
        if(counter <= N){
            // Print the current value of the counter
            cout << counter << " ";
            // Increment the counter
            counter++;
        }
        // Notify all other threads waiting on the condition variable
        cv.notify_all();
    }
}


/**
 * This function prints the even numbers from 1 to N.
 * It waits for the condition variable to be notified that the counter is even.
 * When the condition variable is notified, it prints the current value of the counter.
 * It then increments the counter and notifies all other threads waiting on the condition variable.
 */
void print_even(){
    // Keep running until we have printed all even numbers from 1 to N
    while(counter <= N){
        // Create a lock that can be used to wait for the condition variable
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until the condition variable is notified that the counter is even
        cv.wait(lock, [] { return counter % 2 == 0; });

        // If the counter has not exceeded N, then print the current value of the counter
        if(counter <= N){
            cout << counter << " ";
            // Increment the counter
            counter++;
        }
        // Notify all other threads waiting on the condition variable that the counter has been incremented
        cv.notify_all();
    }
}

int main(){
    std::thread t1(print_odd);
    std::thread t2(print_even);

    t1.join();
    t2.join();

    return 0;
}