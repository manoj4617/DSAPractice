#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes an index i, a vector of integers nums, and a boolean even
 * and returns the maximum alternating sum of a subsequence of nums starting
 * from index i.
 *
 * The function uses dynamic programming to store the results of previous
 * computations so that they can be reused. The dp array has two columns, one
 * for even indices and one for odd indices. The dp[i][even] element stores the
 * maximum alternating sum of a subsequence of nums starting from index i and
 * ending at an even index if even is true, or an odd index if even is false.
 *
 * The function first checks if the result for the current index i and boolean
 * even is already computed and stored in the dp array. If it is, the function
 * returns the stored result directly.
 *
 * If the result is not computed before, the function calculates the maximum
 * alternating sum by considering two options: 1) include the current element
 * in the subsequence and recursively call the function with the next index
 * and the opposite value of even, and 2) exclude the current element from the
 * subsequence and recursively call the function with the next index and the
 * same value of even. The function returns the maximum of the two options.
 */
long long dfs(int i, vector<int>& nums, int even, vector<vector<int>>& dp){
    if(i == nums.size()){
        // Base case: if we have reached the end of the vector of numbers, return 0
        return 0;
    }

    if(dp[i][even] != -1){
        // If the result for the current index and boolean is already computed and stored in the dp array, return the stored result directly
        return dp[i][even];
    }

    // Calculate the maximum alternating sum by considering two options
    long long total = even ? nums[i] : -nums[i];
    dp[i][even] = max(total + dfs(i + 1, nums, !even, dp), 
                    dfs(i + 1, nums, even, dp));
    return dp[i][even];
}

long long maxAlternatingSun(vector<int>& nums){
    vector<vector<int>> dp(nums.size(), vector<int>(2,-1));
    return dfs(0,nums, 1, dp);
}

int main(){
    vector<int> nums = {4,2,5,3,7};
    cout << maxAlternatingSun(nums) << endl;
    return 0;
}