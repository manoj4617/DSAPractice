#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int rows = triangle.size();
    // Create a dp array with size rows + 1 and initialize with 0
    // The dp array will store the minimum path sum from the current position to the bottom of the triangle
    vector<int> dp(rows + 1, 0);
    
    // Start from the bottom row and move upwards
    // The idea is to use a bottom-up approach to calculate the minimum path sum
    for(int i = rows - 1; i >= 0; --i){
        // Iterate through each element in the current row
        for(int j = 0; j < triangle[i].size(); ++j){
            // Update dp[j] to be the current element plus the minimum of the two elements directly below it
            // This ensures that dp[j] always contains the minimum path sum from the current element to the bottom
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }
    // The top element of dp array will contain the minimum path sum from the top to the bottom of the triangle
}

int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}