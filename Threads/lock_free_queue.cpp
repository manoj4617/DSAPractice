#include <iostream>
#include <atomic>
#include <stdatomic.h>
#include <vector>
#include <thread>

using namespace std;

class LockFreeQueue {

    private:
        vector<int> buffer;
        atomic<int> rear, front;
        int capacity;
    
    public:
        LockFreeQueue(int cap) :
            capacity(cap), buffer(cap), front(0), rear(0) {}
        
        bool enqueue(int element){
            int r;
            do{
                r = rear.load(std::memory_order_relaxed);
                if((r + 1) % capacity == front.load(std::memory_order_relaxed)){
                    return false;
                }
            }while(!rear.compare_exchange_weak(r, (r + 1) % capacity,
            std::memory_order_release, std::memory_order_relaxed));
            buffer[r] = element;
            return true;
        }

        bool dequeue(int &item){
            int f;
            do{
                f = front.load(std::memory_order_acquire);
                if(f == rear.load(std::memory_order_relaxed)){
                    return false;
                }
            }while(!front.compare_exchange_weak(f, (f+1) % capacity, std::memory_order_release,
                std::memory_order_relaxed));
            item = buffer[f];
            return true;
        }
};

void printQueue(LockFreeQueue &que){
    int item;
    while(que.dequeue(item)){
        cout << "Dequeued: " << item << endl;
    }
}

int main(){
    LockFreeQueue que(16);
    thread t1([&que](int x) { que.enqueue(x); }, 1);
    thread t2([&que](int x){que.enqueue(x);}, 2);
    thread t3([&que](int x){que.enqueue(x);}, 3);

    
    t1.join();
    t2.join();
    t3.join();
    printQueue(que);
    return 0;
}
