#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief Given an array nums of n integers and an integer target, 
 * find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers. If there are multiple 
 * answers, return any of them.
 * 
 * @param nums Array of integers
 * @param target Target sum
 * @return int Closest sum to target
 */
int threeSumClosest(vector<int>& nums, int target){

    // If the size of the array is less than 3, there is no possible solution
    if(nums.size() < 3)
        return -1;

    // Initially set the closest sum to the sum of the first 3 elements in the array
    int closeDiff = nums[0] + nums[1] + nums[2];

    // Calculate the absolute difference between the initial closest sum and target
    int diff = abs(closeDiff - target);

    // Sort the array to make it easier to find the closest sum
    sort(nums.begin(), nums.end());

    // Loop through the array from start to one position before the end,
    // to avoid duplicate triplets 
    for(int i=0;i<nums.size() - 2; i++){

        // Initialize the indices of the lowest and highest elements in the triplet
        int low = i + 1;
        int high = nums.size() - 1;

        // Temporary variable to store the sum of the three elements
        int sum = 0;

        // Loop through the array from one position after the lowest element
        // to the end, to find the other two elements that sum to closest to target
        while(low < high){

            // Calculate the sum of the three elements
            sum = nums[i] + nums[low] + nums[high];

            // Calculate the absolute difference between the current sum and target
            int newDiff = abs(sum - target);

            // If the current sum is closer to target than the previous closest sum
            if(newDiff < diff){

                // Update the closest sum and its absolute difference
                closeDiff = sum;
                diff = newDiff;
            }

            // If the current sum is greater than target
            if(sum > target)

                // Decrement the highest index to find a lower value
                high--;

            // If the current sum is less than or equal to target
            else

                // Increment the lowest index to find a higher value
                low++;
        }   
    }

    // Return the closest sum to target
    return closeDiff;
}


int main(){

    int n, target;
    vector<int> nums;

    cin >> n >> target;

    for(int i=0;i<n;++i)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << threeSumClosest(nums, target) << "\n";
    return 0;
}
