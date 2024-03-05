#include <iostream>
#include <vector>
using namespace std;

void move_zeroes(vector<int>& nums){
    int i = 0 , j = 0;

    while(j < nums.size()){
        if(nums[j] != 0){
            swap(nums[i], nums[j]);
            i++;
        }
       j++;
    }
}

int main(){
    int n;
    vector<int> nums;

    cin >> n;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << "Before moving zeroes: ";
    for(int i=0;i<n;++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "After moving zeroes: ";
    move_zeroes(nums);
    for(int i=0;i<n;++i){
        cout << nums[i] << " ";
    }
}