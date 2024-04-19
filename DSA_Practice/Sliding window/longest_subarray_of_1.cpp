#include <iostream>
#include <vector>

using namespace std;

/**
* This function finds the length of the longest subarray
* of 1s with at most one 0 in the array.
* @param nums: the input vector of 0s and 1s
* @return: the length of the longest subarray of 1s with at most one 0
*/
int longestSubarray(vector<int>& nums) {
    // Base case: if the input vector is empty, return 0
    if(nums.empty())
        return 0;
    
    // Initialize three variables to keep track of the subarray:
    //  start: the starting index of the subarray
    //  end: the ending index of the subarray (not inclusive)
    //  max_len: the maximum length of the subarray found so far
    int start = 0, end = 0, max_len = INT_MIN;
    
    // Initialize a variable to keep track of the number of 0s
    // encountered so far in the subarray
    int zeroCount = 0;
    
    // The size of the input vector
    int n = nums.size();
    
    // Loop through the input vector, updating the subarray indices and
    // the maximum length found so far
    while(end < n){
        // If the current element is a 0, increment the number of 0s
        if(nums[end] == 0){
            zeroCount++;
        }
        
        // If the number of 0s encountered so far is <= 1, the subarray
        // may be part of the solution, so update the maximum length
        // accordingly. The -zeroCount term handles the case where the
        // subarray only contains 0s, in which case the length is 0.
        if(zeroCount <= 1){
            max_len = max(max_len, end - start + 1 - zeroCount);
        }
        
        // If the number of 0s encountered so far is > 1, we need to
        // shrink the subarray by moving the starting index forward
        // until we have <= 1 0s. The while loop below does this.
        while(zeroCount > 1){
            // If the element at the starting index is a 0, decrement
            // the number of 0s
            if(nums[start] == 0)
                zeroCount--;
            // Move the starting index forward
            start++;
        }
        
        // Move the ending index forward
        end++;
    }
    
    // If the maximum length is equal to the size of the input vector,
    // return the maximum length - 1, since the entire input vector
    // is a subarray of 1s with at most one 0.
    return max_len == n ? max_len - 1: max_len;
}

int main(){
    vector<int> nums;
    int n;

    cin >> n;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    cout << longestSubarray(nums);
    return 0;
}