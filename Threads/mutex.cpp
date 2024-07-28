#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;
void printMessage(const string& msg){
   lock_guard<mutex> lock(mtx);
   cout << msg << endl;
}

int main(){
    thread t1(printMessage, "Hello from thead 1");
    thread t2(printMessage, "Hello from thead 2");

    t1.join();
    t2.join();

    return 0;
}

