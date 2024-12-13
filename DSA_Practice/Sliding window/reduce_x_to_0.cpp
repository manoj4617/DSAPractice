#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

/* Problem
You are given an integer array nums and an integer x. 
In one operation, you can either remove the leftmost or the rightmost element from the array nums 
and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

*/

int minOperations(vector<int>& nums, int x){
    // Calculate the total sum of the array
    int total_sum = accumulate(nums.begin(), nums.end(), 0);

    // Calculate the required sum that we need to reach by removing elements from the array
    int required_sum = total_sum - x;

    // Initialize two pointers, start and end, to 0 and 0 respectively.
    // Start will point to the first element of the array, and end will point to the last element of the array.
    // We will use these two pointers to create a sliding window of elements in the array.
    int start = 0;
    int end = 0;

    // Initialize the length of the array
    int len = nums.size();

    // Initialize a variable max_len to INT_MIN, which is the minimum value of an int.
    // This variable will store the maximum length of the subarray that sums up to the required_sum.
    int max_len = INT_MIN;

    // Initialize a variable sum to 0, which will store the sum of the elements in the current window.
    int sum = 0;

    // While end is less than the length of the array, keep expanding the window by moving the end pointer to the right.
    while(end < len){
        // Add the current element in the array to the sum.
        sum += nums[end];

        // While the sum is greater than the required_sum, shrink the window by moving the start pointer to the right.
        while(sum > required_sum && start <= end){
            // Subtract the current element from the sum.
            sum -= nums[start];

            // Move the start pointer to the right.
            start++;
        }

        // If the sum is equal to the required_sum, update the max_len variable with the maximum length of the subarray.
        if(sum == required_sum){
            max_len = max(max_len, end - start + 1);
        }

        // Move the end pointer to the right.
        end++;
    }

    // If max_len is not equal to INT_MIN, it means we have found a subarray that sums up to the required_sum.
    // In this case, return the length of the array minus the maximum length of the subarray.
    if(max_len != INT_MIN){
        return nums.size() - max_len;
    }

    // If max_len is still equal to INT_MIN, it means we have not found a subarray that sums up to the required_sum.
    // In this case, return -1.
    return -1;
}


int main(){
    vector<int> nums = {1,1,4,2,3};
    int x = 5;

    cout << "min operations: " << minOperations(nums, x) << endl;
    nums.clear();
    nums = {5,6,7,8,9};
    x = 4;

    cout << "min operations: " << minOperations(nums, x) << endl;

    nums.clear();
    nums = {3,2,20,1,1,3};
    x = 10;
    cout << "min operations: " << minOperations(nums, x) << endl;

    return 0;
}