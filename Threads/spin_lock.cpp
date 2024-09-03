// spinLock.cpp
#include <chrono>
#include <iostream>
#include <atomic>
#include <thread>

/**
 * @brief Spinlock is a synchronization mechanism that allows only one thread to access a particular resource.
 *
 * How it works in a multi-threaded environment:
 * 1. If a thread wants to access a shared resource, it will first have to acquire the lock.
 * 2. If the lock is not available, the thread will go into a busy-wait loop and continuously check if the lock is available.
 * 3. When the lock is available, the thread will acquire the lock and access the shared resource.
 * 4. When the thread is done with the shared resource, it will release the lock.
 * 5. Other threads that are waiting to access the shared resource will continuously check if the lock is available.
 * 6. When the lock is available, one of the waiting threads will acquire the lock and access the shared resource.
 *
 * The spinlock is more efficient than a mutex when the critical section is very short.
 * But if the critical section is long, the spinlock can cause high CPU usage and is not efficient.
 */
class Spinlock{
  std::atomic_flag flag;
public:
  Spinlock(): flag(ATOMIC_FLAG_INIT){}
  
  void lock(){
    while( flag.test_and_set() );
  }

  void unlock(){
    flag.clear();
  }
};

Spinlock spin;

void workOnResource(){
  spin.lock();
  // shared resource
  std::cout << "ThreadID: " << std::this_thread::get_id() << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  spin.unlock();
  std::cout << "Work done" << std::endl;
}


int main(){
  std::thread t(workOnResource);
  std::thread t2(workOnResource);

  t.join();
  t2.join();

}