#include <iostream>
#include <vector>

using namespace std;

/**
 * Searches for a given value in a matrix and returns its coordinates if found.
 * @param nums The matrix to search.
 * @param k The value to search for.
 * @return A vector containing the row and column of the value in the matrix if it exists, or {-1,-1} if it does not.
 */
vector<int> SearchInMatrix(const vector<vector<int>>& nums, int k){
    // Get the number of rows and columns in the matrix.
    int m = nums.size();
    int n = nums[0].size();

    // Initialize row and column pointers to the top right of the matrix.
    int i = 0;
    int j = n - 1;

    // Continue looping until the pointers are out of bounds.
    while((i >= 0 && i < m) || (j >= 0 && j < n)){
        // Check if the value at the current position is equal to the target value.
        if(nums[i][j] == k){
            // If the value is equal, return its coordinates in the matrix.
            return {i,j};
        }
        // If the value at the current position is greater than the target value, move the column pointer to the left.
        else if(nums[i][j] > k){
            j--;
        }
        // If the value at the current position is less than the target value, move the row pointer down.
        else if(nums[i][j] < k){
            i++;
        }
    }
    // If the loop exits and the value is not found, return {-1,-1}.
    return {-1,-1};
}

int main(){
    vector<vector<int>> num = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,49},
        {32,33,39,50}
    };
    int k = 29;
    vector<int> res = SearchInMatrix(num, k);
    cout << res[0] << ", " << res[1];
    return 0;
}