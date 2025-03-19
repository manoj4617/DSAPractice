#include <iostream>
#include <vector>

using namespace std;

/**
 * Function to find the single non-duplicate element in a vector of integers.
 * The vector is assumed to have an even number of elements, and each element
 * appears twice except for one element which appears only once.
 * 
 * @param nums The vector of integers to search through.
 * @return The single non-duplicate element in the vector.
 */
int SingleNonDuplicate(vector<int> nums)
{
    // Initialize the left and right pointers to the first and last elements of the vector.
    int left = 0;
    int right = nums.size() - 1;

    // Perform a binary search on the vector until the left pointer is not equal to the right pointer.
    while(left != right)
    {
        // Calculate the middle index of the current search window.
        int mid = left + (right - left) / 2;

        // If the middle index is an odd number, decrement it by 1 to get the index of the leftmost even number.
        if(mid % 2 != 0) mid -= 1;

        // Check if the middle element is not equal to the element immediately after it.
        if(nums[mid] != nums[mid + 1])
        {
            // If they are not equal, then the single non-duplicate element must be on the right side of the window.
            // Decrement the right pointer to shrink the window.
            right  = mid;
        }
        else
        {
            // If they are equal, then the single non-duplicate element must be on the left side of the window.
            // Increment the left pointer to shrink the window.
            left = mid + 2;
        }
    }
    
    // The single non-duplicate element is the only element remaining in the window.
    // Return the value at the left pointer.
    return nums[left];
}

int SingleNonDuplicate1(vector<int> nums)
{
    int result = 0;
    for (int num : nums)
    {
        result ^= num;
    }
    return result;
}

int main(){
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << SingleNonDuplicate1(nums) << endl;
    return 0;
}