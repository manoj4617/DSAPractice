#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to determine if you are able to reach the last index.
 *
 * @param arr an array of non-negative integers
 * @return true if we can reach the last index, false otherwise
 */
bool JumpGame(vector<int>& arr){
    // The last element in the array is our target
    int target = arr.size() - 1;
    // Iterate backwards over the array
    for(int i = arr.size() - 2; i > -1; --i){
        // If the current element in the array is greater than or equal to the target,
        // we can reach the target from the current element
        if(target <= arr[i] + i){
            // Update the target to the current element
            target = i;
        }
    }
    // If the target is 0, we can reach the last index
    if(target == 0) return true;
    // Otherwise, we can't reach the last index
    return false;
}


int main(){
    int n;
    vector<int> arr;
    cin >> n;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        arr.push_back(t);
    }
    cout << JumpGame(arr);
}