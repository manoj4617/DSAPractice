#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestLIS(vector<int>& nums){
    // Get the size of the input vector
    int n = nums.size();
    
    // Initialize a dp vector to store the length of the longest increasing subsequence
    // ending at each index. Initially, each position has a subsequence of length 1 (itself).
    vector<int> dp(n, 1);
    
    // Iterate over each element in the input vector
    for(int i = 0; i < n; ++i) {
        // For each element nums[i], compare it with every previous element nums[j]
        for(int j = 0; j < i; ++j) {
            // If a previous element nums[j] is less than the current element nums[i],
            // it can be part of the increasing subsequence ending at index i
            if(nums[j] < nums[i]) {
                // Update the dp[i] to the maximum length found so far by extending
                // the increasing subsequence ending at j with nums[i]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // The length of the longest increasing subsequence is the maximum value in the dp array
    return *max_element(dp.begin(), dp.end());
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cout << longestLIS(nums);
    return 0;
}