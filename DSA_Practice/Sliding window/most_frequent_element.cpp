#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * This function finds the maximum frequency of a given array of integers
 * such that the sum of the elements in the subarray is less than or equal to k.
 * @param nums: the input vector of integers
 * @param k: the given integer
 * @return: the maximum frequency of the given array
 */
int maxFrequency(vector<int>& nums, int k) {
    // Sort the input vector in ascending order
    sort(nums.begin(), nums.end());

    // Initialize two pointers, start and end, to 0
    // The start pointer points to the starting index of the subarray
    // The end pointer points to the ending index of the subarray (not inclusive)
    int start = 0;
    int end = 0;

    // Initialize a variable max_len to INT_MIN
    // max_len stores the maximum length of the subarray found so far
    int max_len = INT_MIN;

    // Initialize a variable cur to 0
    // cur stores the current sum of the subarray
    long cur = 0;

    // Get the size of the input vector
    int len = nums.size();

    // Loop through the input vector, updating the start and end pointers and
    // the maximum length found so far
    while(end < len){
        // Get the current element at the end index
        long num = nums[end];

        // Add the current element to the current sum
        cur += num;

        // If the current sum is greater than k, then we need to shrink the subarray
        // by moving the start pointer forward until the current sum is less than or equal to k
        if((end - start + 1) * num - cur > k){
            // Subtract the element at the start index from the current sum
            cur -= nums[start];

            // Move the start pointer forward
            start++;
        }

        // Update the maximum length found so far
        max_len = max(end - start + 1, max_len);

        // Move the end pointer forward
        end++;
    }

    // Return the maximum length found
    return max_len;
}


int main(){
    vector<int> nums = {1,4,8,13};
    int k = 5;

    cout << maxFrequency(nums, k);
    return 0;
}