#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> dp;
int total_sum = 0;

/**
 * This function uses a depth-first search approach to find all possible
 * subsets of the given array of numbers that sum up to the given target.
 *
 * The function takes in the following parameters:
 *   i: the current index we are at in the given array of numbers
 *   total: the current sum of the subset of numbers we are considering
 *   nums: the given array of numbers
 *   target: the target sum we are trying to reach
 *
 * The function returns the number of subsets that sum up to the target.
 */
int backtrack(int i, int total, vector<int>& nums, int target){
    // Base case: if we have reached the end of the array of numbers, then
    // we check if the current sum is equal to the target sum. If it is, we
    // return 1, otherwise we return 0.
    if(i == nums.size()){
        return total == target;
    }

    // If we have already computed the result of the current subproblem, then
    // we simply return the result from the memoization table.
    if(dp[i][total + total_sum] != INT_MIN){
        return dp[i][total + total_sum];
    }

    // Otherwise, we recursively call the function twice, once with the current
    // number added to the sum and once with the current number subtracted from
    // the sum. We then add up the results of the two recursive calls and
    // return the result modulo 2.
    return dp[i][total + total_sum] = (backtrack(i + 1, total + nums[i], nums, target) +
                                        backtrack(i + 1, total - nums[i], nums, target));
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