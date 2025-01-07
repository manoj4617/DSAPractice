#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;
 /**
  * This function takes a vector of integers and an integer target as input, and
  * returns the number of ways to make up the target value using the given set of
  * integers.
  *
  * The function uses memoization to store the solutions to subproblems of the
  * original problem. The memoization is implemented using an unordered_map, where
  * the key is the target value of the subproblem and the value is the number of
  * ways to make up the target value using the given set of integers.
  *
  * The function first checks if the target value is 0. If it is, the function
  * returns 1, since there is only one way to make up 0 using any set of
  * integers.
  *
  * The function then checks if the solution to the current subproblem has
  * already been computed. If it has, the function returns the precomputed
  * solution. Otherwise, the function iterates over each integer in the given
  * set of integers and recursively calls itself with the updated target value
  * and the current integer as the next integer to consider.
  *
  * The function then sums up the number of ways to make up the target value
  * using the current integer and the number of ways to make up the target value
  * without using the current integer, and stores the result in the memoization
  * map.
  *
  * Finally, the function returns the number of ways to make up the target value
  * using the given set of integers.
  */
int dp(vector<int>& nums, int target){
    if(target == 0){
        return 1;
    }
    if(memo.count(target)){
        return memo[target];
    }
    int count = 0;
    for(int& num : nums){
        if(num <= target){
            count += dp(nums, target - num);
        }
    }
    memo[target] = count;
    return count;
}
int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    // memo[0] = 1;
    // return dp(nums, target);

    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i=1;i<= target;++i){
        dp[i] = 0; 
        for(int& num : nums){
            if(i >= num){
                dp[i] += dp[i - num];
            }
        }
        if(dp[i] > INT_MAX){
            dp[i] = 0;
        }
    }
    return dp[target];
 }

int main(){
    vector<int> nums = {1,2,3};
    int target = 4;
    cout << combinationSum4(nums, target) << endl;
    return 0;
}