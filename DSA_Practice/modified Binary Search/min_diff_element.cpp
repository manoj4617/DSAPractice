#include <iostream>
#include <vector>

using namespace std;

int floor_num(const vector<int>& nums,int  k){
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == k){
            return nums[mid];
        }
        if(nums[mid] < k){
            res = nums[mid];
            low = mid + 1;
        }
        else if(nums[mid] > k){
            high = mid - 1;
        }
    }
    return res;
}

int ceil_num(const vector<int>& nums,int  k){
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == k){
            return nums[mid];
        }
        if(nums[mid] < k){
            low = mid + 1;
        }
        else if(nums[mid] > k){
            res = nums[mid];
            high = mid - 1;
        }
    }
    return res;
}

/**
 * This function finds the element in a sorted vector that has the minimum difference
 * with a given target value.
 *
 * @param nums The sorted vector of integers to search through.
 * @param k The target value to find the minimum difference with.
 * @return The element in the vector that has the minimum difference with the target value.
 */
int MinDiffElement(const vector<int>& nums, int k){
    // Find the floor of k in the vector.
    // If k is in the vector, then the floor of k is k itself.
    int fl = floor_num(nums, k);

    // Find the ceil of k in the vector.
    // If k is in the vector, then the ceil of k is k itself.
    int cl = ceil_num(nums, k);

    // Compare the absolute differences between k and its floor and ceil.
    // If the absolute difference between k and its floor is less than or equal
    // to the absolute difference between k and its ceil, then return the floor.
    if(abs(k - fl) <= abs(k - cl)){
        return fl;
    }
    // Otherwise, return the ceil.
    else{
        return cl;
    }
}

/**
 * This function finds the element in a sorted vector that has the minimum difference
 * with a given target value. It does this by using a binary search algorithm to
 * narrow down the search window until the target value is found, and then compares
 * the absolute differences between the target value and its floor and ceil to
 * determine which has the minimum difference.
 *
 * @param nums The sorted vector of integers to search through.
 * @param k The target value to find the minimum difference with.
 * @return The element in the vector that has the minimum difference with the target value.
 */
int MinDiffElement_2(const vector<int>& nums, int k){
    int low = 0;
    int high = nums.size() - 1;

    // Perform a binary search on the vector until the target value is found.
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == k){
            // If the target value is found, return it.
            return nums[mid];
        }
        if(nums[mid] < k){
            // If the target value is greater than the middle element, then set the low
            // pointer to the middle element + 1 to narrow the search window.
            low = mid + 1;
        }
        else if(nums[mid] > k){
            // If the target value is less than the middle element, then set the high
            // pointer to the middle element - 1 to narrow the search window.
            high = mid - 1;
        }
    }

    // Compare the absolute differences between the target value and its floor and ceil.
    if(abs(k - nums[high]) <= abs(k - nums[low])){
        // If the absolute difference between the target value and its floor is less than
        // or equal to the absolute difference between the target value and its ceil,
        // then return the floor.
        return nums[high];
    }
    else {
        // Otherwise, return the ceil.
        return nums[low];
    }
}
int main(){
    int n,k;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cin >> k;
    // cout << MinDiffElement(nums,k);
    cout << MinDiffElement_2(nums, k);
    return 0;
}