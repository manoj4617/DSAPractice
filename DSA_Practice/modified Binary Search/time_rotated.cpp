#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers as input and returns the number of times the array has been rotated.
 * A rotated array is an array that has been rotated by some number of positions. For example, the array [1,2,3]
 * rotated 1 position is [3,1,2]. The array [1,2,3] rotated 2 positions is [2,3,1].
 *
 * The function works by using a binary search on the array. It starts by comparing the first element of the array
 * to the last element of the array. If the first element is less than or equal to the last element, then the array
 * has not been rotated, so the function returns 0.
 *
 * Otherwise, the function enters a while loop that continues until the low pointer is not less than the high pointer.
 * In each iteration of the loop, the function calculates the midpoint of the current search window and checks if
 * the element at the midpoint is less than the element immediately before it. If it is, then the midpoint is the
 * index of the first element of the rotated array, so the function returns the midpoint.
 *
 * If the element at the midpoint is not less than the element immediately before it, then the function checks if the
 * element at the midpoint is greater than the element immediately after it. If it is, then the midpoint + 1 is the
 * index of the first element of the rotated array, so the function returns the midpoint + 1.
 *
 * If neither of the above conditions are true, then the function narrows the search window to either the left or
 * right half of the array, depending on whether the element at the midpoint is greater than or less than the element
 * at the high pointer. This is done by assigning the midpoint + 1 to the low pointer if the element at the midpoint
 * is greater than the element at the high pointer, and assigning the midpoint - 1 to the high pointer if the element
 * at the midpoint is less than the element at the high pointer.
 *
 * The function then repeats the loop until the search window is empty, at which point it returns 0.
 */
int times_rotated(vector<int>& nums){
    int low = 0;
    int high = nums.size() - 1;
    if(nums[low] <= nums[high]){
        return 0;
    }
    while(low < high){
        int mid = low + (high - low) / 2;

        if(mid > 0 && nums[mid] < nums[mid - 1]){
            return mid;
        }
        if(mid < nums.size() - 1 && nums[mid] > nums[mid + 1]){
            return mid + 1;
        }

        if(nums[mid] > nums[high]){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cout << "Times Rotated: " << times_rotated(nums) << "\n";
    return 0;
}