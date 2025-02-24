#include <iostream>
#include <vector>

using namespace std;

int trap1(vector<int>& height) {
    // Get the size of the height array
    int len = height.size();
    
    // Create two vectors to store the max height to the left and right of each position
    vector<int> maxLeft(len);
    vector<int> maxRight(len);
    
    // Initialize the first element of maxLeft with the first height
    maxLeft[0] = height[0];
    
    // Initialize the last element of maxRight with the last height
    maxRight[len-1] = height[len - 1];
    
    // Fill maxLeft such that maxLeft[i] contains the maximum height to the left of i, inclusive
    for(int i = 1; i < len; ++i) {
        maxLeft[i] = max(maxLeft[i - 1], height[i]);
    }
    
    // Fill maxRight such that maxRight[i] contains the maximum height to the right of i, inclusive
    for(int i = len - 2; i >= 0; --i) {
        maxRight[i] = max(maxRight[i + 1], height[i]);
    }
    
    // Initialize the result to store the total water trapped
    int res = 0;
    
    // Calculate the water trapped at each index by taking the minimum of maxLeft and maxRight at that index
    // and subtracting the height at that index, then add it to the result
    for(int i = 0; i < len; ++i) {
        res += min(maxLeft[i], maxRight[i]) - height[i];
    }
    
    // Return the total water trapped
    return res;
}

/**
 * This function takes a vector of integers and returns the total amount of water that can be
 * trapped between the bars of the histogram formed by the given heights.
 *
 * The function works by maintaining two pointers, one at the beginning of the array and one at
 * the end. It then iterates over the array, moving the pointers towards each other, and at each
 * step it calculates the maximum height of the bars to the left and right of the current position
 * and takes the minimum of the two as the amount of water that can be trapped at that position.
 *
 * The function returns the total amount of water that can be trapped.
 */
int trap2(vector<int>& height) {
    int len = height.size();
    // Initialize the result to store the total water trapped
    int res = 0;
    // Initialize the left and right pointers to the beginning and end of the array, respectively
    int l = 0, r = len - 1;
    // Initialize the maximum heights to the left and right of the current position to the first and
    // last heights
    int maxLeft = height[0], maxRight = height[r];
    // Iterate over the array, moving the pointers towards each other
    while(l < r){
        // If the maximum height to the left is less than the maximum height to the right, move the
        // left pointer one step to the right
        if(maxLeft < maxRight){
            l++;
            // Update the maximum height to the left of the current position
            maxLeft = max(maxLeft, height[l]);
            // Add the amount of water that can be trapped at the current position to the result
            res += maxLeft - height[l];
        }
        // If the maximum height to the left is not less than the maximum height to the right, move the
        // right pointer one step to the left
        else{
            r--;
            // Update the maximum height to the right of the current position
            maxRight = max(maxRight, height[r]);
            // Add the amount of water that can be trapped at the current position to the result
            res += maxRight - height[r];
        }
    }
    // Return the total amount of water that can be trapped
    return res;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap1(height) << endl;

    height.clear();
    height = {4,2,0,3,2,5};
    cout << trap2(height) << endl;
    return 0;

}