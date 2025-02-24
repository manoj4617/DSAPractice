#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> dp;
int total_sum = 0;

int backtrack(int i, int total, vector<int>& nums, int target){
    // Base case
    if(i == nums.size()){
        return target == total;
    }

    if(dp[i][total + total_sum] != INT_MIN){
        return dp[i][total + total_sum];
    }

    return dp[i][total + total_sum] = backtrack(i + 1, total + nums[i], nums, target)  + 
                                        backtrack(i + 1, total - nums[i], nums, target);
}
int target_sum(vector<int>& nums, int target){
    total_sum = accumulate(nums.begin(), nums.end(), 0);
    dp = vector<vector<int>>(nums.size(), vector<int>(2 * total_sum + 1, INT_MIN));
    return backtrack(0,0,nums,target);
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }

    int target;
    cin >> target;
    cout << target_sum(nums, target);
    return 0;
}