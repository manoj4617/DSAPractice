#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief Function to find the maximum subarray sum of 'nums' with at most one
 * distinct element
 *
 * @param nums is the input array of integers
 *
 * @return the maximum subarray sum of 'nums' with at most one distinct element
 *
 * Time complexity: O(n), where 'n' is the length of 'nums'
 * Space complexity: O(m), where 'm' is the number of distinct elements in
 *                   'nums'
 *
 * Explanation:
 * The idea is to use a sliding window of size 'm' (i.e., the number of
 * distinct elements in 'nums'), where 'm' is at most 'n'.
 * We move the right side of the window one step at a time, and keep track of
 * the sum of the subarray of 'nums' spanned by the window. We also keep track
 * of the number of occurrences of each distinct element in the subarray
 * spanned by the window. If the number of occurrences of any element in the
 * subarray is greater than 1, we remove the leftmost occurrence of that
 * element from the sliding window. We repeat this process until the right
 * side of the window reaches the end of 'nums'.
 * The maximum subarray sum of 'nums' with at most one distinct element is
 * the maximum of the sum of all subarrays spanned by the sliding window.
 */
int maximumUniqueSubarray(vector<int>& nums) {
        // 'mp' maps each distinct element in 'nums' to its number of
        // occurrences in the subarray spanned by the sliding window
        unordered_map<int, int> mp;

        // 'maxSum' will store the maximum subarray sum of 'nums' with at most
        // one distinct element
        int maxSum = 0;

        // 'sum' is the sum of the subarray spanned by the sliding window
        int sum = 0;

        // 'start' and 'end' are two pointers used to slide the window of 'nums'
        int start = 0, end = 0;

        while(end < nums.size())
        {
            // Add the current element in 'nums' to 'mp'
            mp[nums[end]]++;

            // Increment the sum of the subarray spanned by the window
            sum += nums[end];

            // If the number of occurrences of any element in the subarray
            // spanned by the window is greater than 1, remove the leftmost
            // occurrence of that element from the window
            while(mp[nums[end]] > 1)
            {
                // Decrement the number of occurrences of the element at
                // 'start' in 'mp'
                mp[nums[start]]--;

                // Remove the element at 'start' from the sliding window
                sum -= nums[start];

                // Move the left side of the window one step to the right
                start++;
            }

            // Update the maximum subarray sum of 'nums' with at most one
            // distinct element
            maxSum = max(maxSum, sum);

            // Move the right side of the window one step to the right
            end++;
        }

        return maxSum;
}


int main(){

    vector<int> nums;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    cout << maximumUniqueSubarray(nums);

    return 0;
}