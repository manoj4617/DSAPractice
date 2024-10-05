#include <iostream>
#include <vector>

using namespace std;

int first_occurance(vector<int>& nums, int k){
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == k){
            res = mid;
            high = mid - 1; // change to high = mid - 1
        }
        else if(nums[mid] > k){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return res;
}


int last_occurance(vector<int>& nums, int k){
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == k){
            res = mid;
            low = mid + 1;
        }
        else if(nums[mid] > k){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return res;
}

int main(){
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cin >> k;
    cout << "first occurance: " << first_occurance(nums, k) << "\n";
    cout << "last occurance: " << last_occurance(nums, k);
    return 0;
}