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

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    cout << "Minimum number of jumps: " << JumpGame2(nums);
}