#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Finds the maximum product of any contiguous subarray of a given array of integers
 * @param nums Array of integers
 * @return The maximum product of any contiguous subarray of nums
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int maxProduct(vector<int>& nums) {
        // Initialize the maximum product of the current subarray to 1 
        // (neutral for multiplication)
        int current_max = 1;
        // Initialize the minimum product of the current subarray to 1
        // (neutral for multiplication)
        int current_min = 1;
        // Initialize the maximum product of the entire array to the minimum value 
        // of an integer (so that it can be updated)
        int global_max = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            // If the current element is negative, swap the current maximum
            // and minimum products with each other
            if (nums[i] < 0) {
                std::swap(current_max, current_min);
            }

            // Update the current maximum product by considering the current
            // element to be either positive or negative
            current_max = std::max(nums[i], current_max * nums[i]);
            // Update the current minimum product by considering the current
            // element to be either positive or negative
            current_min = std::min(nums[i], current_min * nums[i]);

            // Update the global maximum product if the current subarray's
            // product is greater than the global maximum product
            global_max = std::max(global_max, current_max);
        }

        return global_max;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cout << maxProduct(nums);
    return 0;
}