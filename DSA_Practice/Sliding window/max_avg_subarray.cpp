#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
        double max_avg = 0, sum = 0;

        for(int i=0;i<k;++i){
            sum += nums[i];
        }
        max_avg = sum / k;

        int t = k;
        for(int i=0;i<nums.size() - t; ++i){
            sum -= nums[i];
            sum += nums[k++];
            max_avg = max(max_avg , sum/t);
        }

        return max_avg;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cout << findMaxAverage(nums,k);
    return 0;
}