#include <iostream>
#include <vector>

using namespace std;

/*
Key Insight: Think about bursting balloons in REVERSE order - which balloon to burst LAST
instead of which to burst first. This gives us a more manageable subproblem structure.

Why this works:
1. When we burst a balloon first, the adjacent balloons become neighbors, changing future calculations
2. But if we think about which balloon to burst LAST:
   - The last balloon we burst will always multiply with the numbers outside our current subarray
   - This gives us well-defined subproblems that don't affect each other

Example for nums = [4,2,3,7]:
- We add 1's at boundaries: [1,4,2,3,7,1]
- For each subarray, we try each position as the last balloon to burst
- When we burst at position i, we get:
  * nums[left-1] * nums[i] * nums[right+1] coins for current burst
  * Plus optimal solutions for subarrays (left to i-1) and (i+1 to right)
*/


int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp){
    // Base case: l > r means we have no more balloons to burst
    if(l > r) return 0;

    // If we've already computed the optimal solution for this subarray,
    // just return the stored result.
    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 0;

    // Try each position i in the subarray [l,r] as the last balloon to burst
    // We want to find the optimal bursting order, so we consider all possibilities
    for(int i=l;i<=r;++i){
        // Coins from last burst: left boundary * current * right boundary
        // We always multiply the current balloon with its neighbors
        int coins = nums[l-1] * nums[i] * nums[r+1];

        // Add optimal solutions for left and right subarrays
        // When we burst at position i, we partition the array into two subproblems:
        // left subarray (l to i-1) and right subarray (i+1 to r)
        // We take the maximum of the two subproblems and add it to the current coins
        coins += dfs(l,i-1,nums,dp) + dfs(i+1,r,nums,dp);

        // Keep track of the maximum coins we've seen so far
        dp[l][r] = max(dp[l][r], coins);
    }
    return dp[l][r];
}

int maxCoins(vector<int>& nums){
    // Add 1 at the begining and end of the array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    return dfs(1,n-2,nums,dp);
}

int main(){
    vector<int> nums = {4,2,3,7};
    cout << "Max Coins after bursting all Balloons: " << maxCoins(nums) << endl;
    return 0;
}