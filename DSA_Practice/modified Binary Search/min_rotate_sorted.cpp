 #include <iostream>
 #include <vector>
 using namespace std;
 
 int findMin(vector<int>& nums) {
    // Initialize two pointers, low and high, to the start and end of the array
    int low = 0;
    int high = nums.size() - 1;

    // Continue the loop until low and high converge
    while (low < high) {
        // Calculate the mid-point of the current search window
        int mid = low + (high - low) / 2;

        // If the middle element is less than the element at high,
        // it means the minimum value is in the left part of the array
        if (nums[mid] < nums[high]) {
            // Move the high pointer to mid, narrowing the search window to the left
            high = mid;
        } else {
            // Otherwise, the minimum value is in the right part of the array
            // Move the low pointer to mid + 1, narrowing the search window to the right
            low = mid + 1;
        }
    }

    // At the end of the loop, low will point to the minimum element
    return nums[low];
}

    int main(){
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << findMin(nums) << endl;
        return 0;
    }