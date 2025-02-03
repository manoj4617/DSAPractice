#include <iostream>
#include <vector>

using namespace std;

int JumpGame2(vector<int>& nums) {
    // Get the size of the nums array
    int n = nums.size();
    
    // Initialize a vector to store the minimum number of jumps needed to reach
    // the end from each position, setting all values to INT_MAX initially
    vector<int> minJump(n, INT_MAX);
    
    // The last position requires 0 jumps to reach the end since it is already the end
    minJump[n - 1] = 0;
    
    // Iterate from the second-to-last element down to the first
    for(int i = n - 2; i >= 0; --i) {
        // Calculate the farthest position we can jump to from the current position
        int maxJump = min(i + nums[i], n - 1);
        
        // Check all positions we can reach from the current position
        for(int j = i + 1; j <= maxJump; ++j) {
            // If the position is reachable (i.e., it has been updated from INT_MAX),
            // update the minimum jumps needed to reach the end from the current position
            if(minJump[j] != INT_MAX) {
                minJump[i] = min(minJump[i], minJump[j] + 1);
            }
        }
    }
    
    // Return the minimum number of jumps needed to reach the end from the first position
    return minJump[0];
}

/**
 * @brief This function computes the minimum number of jumps needed to reach the end from the first position in a given vector of integers.
 * 
 * The algorithm works as follows:
 * 1. Initialize result variable res to 0, and two pointers l and r to 0.
 * 2. While r is less than n - 1 (i.e., the last position in the array), do the following steps.
 *    a. Initialize farthest to 0, which stores the farthest reachable position from the current position.
 *    b. Iterate from l to r, and for each position i, update farthest to be the maximum of its current value and nums[i] + i.
 *    c. Set l to r + 1, and r to farthest. This effectively moves the window to the right.
 *    d. Increment res by 1.
 * 3. Return res.
 */
int JumpGame2_v2(vector<int>& nums) {
    if(nums.empty()) return 0; // Handle empty input

    int res = 0, l = 0, r = 0;
    int n = nums.size();
    
    while(r < n - 1) {
        // Find the farthest reachable position from the current position
        int farthest = 0;
        for(int i = l; i <= r; ++i) {
            farthest = max(farthest, nums[i] + i);
        }
        
        // Move the window to the right
        l = r + 1;
        r = farthest;
        res++; // Increment the number of jumps
    }
    
    return res;
}


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    cout << "Minimum number of jumps: " << JumpGame2_v2(nums);
}