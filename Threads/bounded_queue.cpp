#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
#include <deque>
#include <mutex>
#include <condition_variable>

using namespace std;

class LockFreeBoundedQueue {
private:
    vector<int> buffer;
    atomic<int> front, rear;
    int capacity;

public:
    LockFreeBoundedQueue(int cap) : capacity(cap), buffer(cap), front(0), rear(0) {}

    bool enqueue(int element) {
        int rear_pos;
        do {
            rear_pos = rear.load(memory_order_relaxed);
            int next_rear = (rear_pos + 1) % capacity;
            if (next_rear == front.load(memory_order_acquire)) {
                return false;  // Queue is full
            }
        } while (!rear.compare_exchange_weak(rear_pos, (rear_pos + 1) % capacity, memory_order_release, memory_order_relaxed));

        buffer[rear_pos] = element;
        return true;
    }

    bool dequeue(int &element) {
        int front_pos;
        do {
            front_pos = front.load(memory_order_relaxed);
            if (front_pos == rear.load(memory_order_acquire)) {
                return false;  // Queue is empty
            }
        } while (!front.compare_exchange_weak(front_pos, (front_pos + 1) % capacity, memory_order_release, memory_order_relaxed));

        element = buffer[front_pos];
        return true;
    }

    int size() {
        return (rear.load(memory_order_acquire) - front.load(memory_order_acquire) + capacity) % capacity;
    }
};


class BoundedBlockingQueue {
    private:
        int cap;
        int cur_size;
        deque<int> dq;
        mutex mtx;
        condition_variable cv_enqueue, cv_dequeue;
    
    public:
        BoundedBlockingQueue(int capacity) : cap(capacity), cur_size(0) {}
    
        void enqueue(int element) {
            unique_lock<mutex> lock(mtx);
            cv_enqueue.wait(lock, [this](){ return cur_size < cap; });  
            
            dq.push_front(element);
            cur_size++;
    
            cv_dequeue.notify_one();  
        }
    
        int dequeue() {
            unique_lock<mutex> lock(mtx);
            cv_dequeue.wait(lock, [this](){ return cur_size > 0; });  
    
            int element_remove = dq.back();
            dq.pop_back();
            cur_size--;
    
            cv_enqueue.notify_one();  
            return element_remove;
        }
    
        int size() {
            unique_lock<mutex> lock(mtx);  
            return cur_size;
        }
    };