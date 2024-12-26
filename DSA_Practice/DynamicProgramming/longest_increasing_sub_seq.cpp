#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Helper function for computing the length of the longest increasing subsequence using recursion.
 * 
 * This function uses a depth-first search (DFS) approach to explore all possible subsequences and find the longest increasing one.
 * 
 * @param nums A vector of integers representing the input sequence.
 * @param i The current index in the nums vector being considered.
 * @param j The index of the last included element in the current subsequence.
 * @return int The length of the longest increasing subsequence starting from index i.
 * 
 * The algorithm works as follows:
 * 1. If the current index i is equal to the size of the nums vector, return 0. This is the base case indicating that we have reached the end of the vector.
 * 2. Recursively compute the length of the LIS without including the current element nums[i]. This is done by calling dfs with the next index (i + 1) and the same last included index (j).
 * 3. If the current element nums[i] can be included in the subsequence (i.e., if j is -1 or nums[j] < nums[i]), compute the length of the LIS including the current element. This is done by calling dfs with the next index (i + 1) and the current index (i) as the new last included index.
 * 4. Return the maximum of the two computed lengths (including and not including the current element).
 */
int dfs(vector<int>& nums, int i , int j){
    if(i == nums.size()){
        return 0;
    }

    // Compute the length of LIS without including nums[i]
    int LIS = dfs(nums, i + 1, j);
    if(j == -1 || nums[j] < nums[i]){
        // Compute the length of LIS including nums[i]
        LIS = max(LIS, 1 + dfs(nums, i + 1, i));
    }
    return LIS;
}

/**
 * @brief Computes the length of the longest increasing subsequence in a given vector of integers using recursion.
 * 
 * This function serves as a wrapper for the recursive dfs function, initializing the parameters for the first call.
 * 
 * @param nums A vector of integers representing the input sequence.
 * @return int The length of the longest increasing subsequence.
 */
int longest_increasing_sub_seq_recurssive(vector<int>& nums){
    return dfs(nums,0,-1);
}

/**
 * @brief Computes the length of the longest increasing subsequence in a given vector of integers.
 * 
 * This function uses dynamic programming to find the longest increasing subsequence (LIS) in the input vector.
 * It maintains a dp array where dp[i] represents the length of the longest increasing subsequence starting at index i.
 * 
 * @param nums A vector of integers representing the input sequence.
 * @return int The length of the longest increasing subsequence.
 * 
 * The algorithm works as follows:
 * 1. Initialize a dp array of the same length as nums, with each element set to 1. This is because the minimum length of LIS ending at any element is 1 (the element itself).
 * 2. Iterate over the nums array from the end to the beginning.
 * 3. For each element nums[i], iterate over the elements to its right (nums[j] where j > i).
 * 4. If nums[i] is less than nums[j], update dp[i] to be the maximum of its current value and 1 + dp[j]. This means that if nums[i] can be followed by nums[j] in an increasing subsequence, then the length of the LIS ending at nums[i] is at least 1 + the length of the LIS ending at nums[j].
 * 5. Finally, return the maximum value in the dp array, which represents the length of the longest increasing subsequence in the entire array.
 */
int longest_increasing_sub_seq(vector<int>& nums){
    int len = nums.size();
    vector<int> dp(len, 1);

    for(int i = len - 1; i >= 0; --i){
        for(int j = i + 1; j < len; ++j){
            if(nums[i] < nums[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0;i < n;++i){
        cin >> nums[i];
    }

    cout << longest_increasing_sub_seq(nums);
    // cout << longest_increasing_sub_seq_recurssive(nums);
    return 0;
}