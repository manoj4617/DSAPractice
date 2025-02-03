#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;



bool isValid(vector<int>& nums, int n , int k , int max_val){
        int x = 1;
        int sum = 0;

        for(int i=0;i<n;++i){
            sum += nums[i];
            if(sum > max_val){
                x++;
                sum = nums[i];
            }
            if( x > k){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k){
            return -1;
        }
        int low = nums[0];
        for(const int& m : nums){
            low = max(low, m);
        }
        int high = accumulate(nums.begin(),nums.end(), 0);
        int res = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(isValid(nums, n , k , mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }

int main(){
    vector<int> nums = {7,2,5,10,12};
    int k = 2;
    int res = splitArray(nums, k);
    cout << res << endl;
    return 0;
}