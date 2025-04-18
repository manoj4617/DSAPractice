#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
// #include <atomic>

using namespace std;

class ThreadSafeQueue{

private:
    deque<int> queue;
    int capacity;
    mutex mtx;
    condition_variable push_cv;
    condition_variable pop_cv;

public:
    ThreadSafeQueue(int cap) : capacity(cap){} 

    bool push(int num){
        unique_lock<mutex> lock(mtx);
        pop_cv.wait(lock, [&](){return queue.size() < capacity;});
        queue.push_back(num);
        push_cv.notify_all();
        return true;
    }

    int pop(){
        unique_lock<mutex> lock(mtx);
        push_cv.wait(lock, [&](){return !queue.empty();});
        int num = queue.front();
        queue.pop_front();
        pop_cv.notify_all();
        return num;
    } 

    int cur_size(){
        // int s = size.load();
        lock_guard<mutex> lock(mtx);
        return queue.size();
    }
};

mutex print_mtx;
void push_to_queue(ThreadSafeQueue *qu, int num){
    bool status = qu->push(num);
    if(status){
        lock_guard<mutex> lock(print_mtx);
        cout << "Pushed element: " << num << "\n";
        return;
    }
    cout << "Push failed: " << num << "\n";
}

void pop_from_queue(ThreadSafeQueue *qu){
    int discard = qu->pop();
    lock_guard<mutex> lock(print_mtx);
    cout << "Popped element: " << discard << "\n";
}

int main(){

    ThreadSafeQueue *que = new ThreadSafeQueue(10);

    thread t1(push_to_queue, que, 10);
    cout << "Queue size: " << que->cur_size() << "\n";
    thread t2(push_to_queue, que, 2);
    thread t3(push_to_queue, que, 3);
    cout << "Queue size: " << que->cur_size() << "\n";
    cout << "Queue size: " << que->cur_size() << "\n";
    thread t4(push_to_queue, que, 5);
    thread t8(push_to_queue, que, 14);
    thread t9(push_to_queue, que, 40);
    cout << "Queue size: " << que->cur_size() << "\n";


    thread t5(pop_from_queue, que);

    cout << "Queue size: " << que->cur_size() << "\n";
    thread t6(pop_from_queue, que);
    thread t7(pop_from_queue, que);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    return 0;
}