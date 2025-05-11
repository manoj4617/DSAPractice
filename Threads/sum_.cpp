#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


using namespace std;

int sum = 0;
int p = 0;
mutex mtx;

void add(vector<int> nums){
    while(p < nums.size()){
        unique_lock<mutex> lock(mtx);
        if(p < nums.size()){
            sum += nums[p];
            p++;
        }
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};

    thread t1(add, nums);
    thread t2(add, nums);
    thread t3(add, nums);
    thread t4(add, nums);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << sum ;

    return 0;

}