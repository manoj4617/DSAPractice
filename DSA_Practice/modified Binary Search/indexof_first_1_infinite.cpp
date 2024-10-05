#include <iostream>
#include <vector>

using namespace std;


/**
 * This function takes a vector of integers as input and returns the index of the first 1 in the array.
 * If no 1 is present in the array, the function returns -1.
 * The function assumes that the array is infinite, and therefore does not check for out of bounds conditions.
 * @param nums The array to search.
 * @return The index of the first 1 in the array, or -1 if no 1 is present.
 */
int IndexOfFirstOne(const vector<int>& nums){
    // If the array only has one element, check if it is 1.
    if(nums.size() == 1){
        if(nums[0] == 1) return 0;
        else return -1;
    }
    // Set the low and high pointers to the first and second elements of the array.
    int low = 0;
    int high = 1;

    // Expand the search window until the value at the high pointer is 1.
    while(nums[high] != 1){
        // Set the low pointer to the current high pointer.
        low = high;
        // Multiply the high pointer by 2 to expand the search window.
        high *= 2;
    }
    // Perform a binary search in the search window established above.
    int res = -1;
    while(low <= high){
        // Calculate the midpoint of the current search window.
        int mid = low + (high - low) / 2;

        // Check if the value at the midpoint is 1.
        if(nums[mid] == 1){
            // If the value at the midpoint is 1, set the result to the midpoint and move the high pointer to the midpoint - 1.
            res = mid;
            high = mid - 1;
        }
        // If the value at the midpoint is 0, move the low pointer to the midpoint + 1.
        if(nums[mid] == 0){
            low = mid + 1;
        }
        // If the value at the midpoint is 1, move the high pointer to the midpoint - 1.
        else{
            high = mid - 1;
        }
    }
    // If the search window is empty, return -1.
    return res;
}

int main(){
    vector<int> nums;
    int temp;
    cin >> temp;
    while(temp != -1){
        nums.push_back(temp);
        cin >> temp;
    }
    cout << IndexOfFirstOne(nums);
    return 0;
}