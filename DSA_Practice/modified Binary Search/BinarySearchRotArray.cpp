#include <iostream>
#include <vector>

using namespace std;

/**
 * This function performs a binary search on a rotated sorted array to find a target element.
 * 
 * @param nums The vector of integers to search through.
 * @param target The target value to find in the vector.
 * @return The index of the target value in the vector, or -1 if the target value is not found.
 */
int BinarySearchRotated(vector<int>& nums, int target)
{
    // Initialize the high and low pointers to the first and last elements of the array.
    int l = nums.size() - 1;
    int low = 0;
    int high = l;

    // Perform a binary search on the array until the low pointer is less than or equal to the high pointer.
    while(low <= high){
        // Calculate the middle index of the current search window.
        int mid = low + (high - low) / 2;
        
        //To handle duplicates
        if(nums[low] == nums[mid] && nums[high] == nums[mid]){
            low++;
            high--;
        }

        // If the middle element is equal to the target, return its index.
        if(nums[mid] == target){
            return mid;
        }
        
        // If the first element of the array is less than or equal to the middle element,
        // then the target value could be in the left or right half of the array.
        if(nums[low] <= nums[mid]){
            // If the target value is between the first element and the middle element,
            // then search the right half of the array.
            if(nums[low] <= target && target < nums[mid]){
                high = mid - 1;
            } 
            // Otherwise, search the left half of the array.
            else{
                low = mid + 1;
            }
        }
        // Otherwise, the target value could be in the right half of the array.
        else{
            // If the target value is between the middle element and the last element,
            // then search the right half of the array.
            if(nums[mid] < target && target <= nums[high]){
                low = mid + 1;
            } 
            // Otherwise, search the left half of the array.
            else{
                high = mid - 1;
            }
        }
    }
    // If the target value is not found, return -1.
    return -1;
}


void reverse_array(vector<int>& arr, int start, int end){
    while(start < end){
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rotate_array(vector<int>& arr,int d){
    if(d == 0)
        return;

    d = d%arr.size();

    reverse_array(arr,0,arr.size()-1);
    reverse_array(arr,0,d-1);
    reverse_array(arr,d,arr.size()-1);
}

int main(){
    int n, rotation;
    cin >> n >> rotation;
    vector<int> nums(n);

    for(int i=0;i<n;++i){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int k;
    cin >> k;

    rotate_array(nums,rotation);
    if(int result = BinarySearchRotated(nums, k) == -1){
        cout << "Not found!\n";
    }else{
        cout << "Found at: \n" << result;
    }

}
