#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& nums, int t){
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = low + (high - low + 1)/2;
        if(nums[mid] == t)
            return mid;
        if(nums[mid] > t){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

/**
 * This function finds the k closest elements to a target in a given vector.
 * 
 * @param nums The vector of integers to search through.
 * @param k The number of closest elements to find.
 * @param target The target value to find the closest elements to.
 * @return A vector of the k closest elements to the target.
 */
vector<int> kClosest(vector<int>& nums, int k, int target){

    // If the size of the vector is equal to k, then return the vector as is.
    if(nums.size() == k) return nums;

    // If the target is less than or equal to the smallest element in the vector,
    // then return the first k elements in the vector.
    if(target <= nums[0]) return vector<int>(nums.begin(), nums.begin() + k);

    // If the target is greater than or equal to the largest element in the vector,
    // then return the last k elements in the vector.
    if(target >= nums[nums.size() - 1]) return vector<int>(nums.end() - k, nums.end());

    // Binary search to find the index of the first element that is closest to the target.
    int firstClosest = binary_search(nums, target);

    // Initialize the indices of the window to be one index before and one index after the first closest element.
    int winLeft = firstClosest - 1;
    int winRight = winLeft + 1;

    // While the size of the window is less than k,
    // expand the window by moving the indices of the window.
    while((winRight - winLeft - 1) < k){

        // If the left index is at the beginning of the vector, move the right index to the right and continue.
        if(winLeft == -1){
            winRight += 1;
            continue;
        }

        // If the right index is at the end of the vector, or if the absolute difference between the target and the element
        // at the left index is less than or equal to the absolute difference between the target and the element at the right index,
        // then move the left index to the right.
        if(winRight == nums.size() || (abs(nums[winLeft] - target) <= abs(nums[winRight] - target))){
            winLeft += 1;
        }
        else{
            // Otherwise, move the right index to the left.
            winRight -= 1;
        }
    }

    // Return a vector containing the elements in the window.
    return vector<int>(nums.begin() + winLeft + 1, nums.begin() + winRight);
}


void PrintList(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << " ";
    }
}

int main() {
    vector<vector<int>> numbersList = {{1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5}, {1, 2, 4, 5, 6}, {1, 2, 3, 4, 5, 10}};
    vector<int> k = {4, 4, 2, 3};
    vector<int> num = {4, 3, 10, -5};

    for (int i = 0; i < numbersList.size(); i++) {
        cout << i + 1 << ".\tThe " << k[i] << " Closest Elements for the number " << num[i] << " in the array ";
        PrintList(numbersList[i]);
        cout << " are: ";
        PrintList(kClosest(numbersList[i], k[i], num[i]));
        cout << std::endl;
        cout << std::string(89, '-') << endl;
    }
}