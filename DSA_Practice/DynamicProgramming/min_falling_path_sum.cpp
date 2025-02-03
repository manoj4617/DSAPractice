#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * This function is a depth-first search (DFS) helper function for the
 * minFallingPathDSum function. It takes the following parameters:
 *
 * n: the number of rows in the matrix
 * row: the current row to search
 * col: the current column to search
 * matrix: the matrix to search
 * memo: the memoization table to store the solutions to subproblems
 *
 * The function returns the minimum falling path sum from the given position
 * (row, col) to the bottom of the matrix.
 *
 * The function works by recursively searching the three possible directions
 * from the current position: directly down, down-right, and down-left. It
 * returns the minimum sum of the three possible paths.
 *
 * If the current position is out of bounds of the matrix, the function returns
 * INT_MAX, which is a sentinel value to indicate that the path is invalid.
 *
 * If the current position is at the bottom row of the matrix, the function
 * returns the value at that position, since there is no more path to search.
 *
 * If the subproblem has already been solved, the function returns the stored
 * solution from the memoization table.
 */
int dfs(int n, int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& memo){
    // if the current position is out of bounds, return a sentinel value
    if(col < 0 || col >= n){
        return INT_MAX;
    }

    // if the current position is at the bottom row, return the value at that position
    if(row == n - 1){
        return matrix[row][col];
    }

    // if the subproblem has already been solved, return the stored solution
    if(memo[row][col] != -1){
        return memo[row][col];
    }

    // recursively search the three possible directions from the current position
    int directDown = dfs(n, row + 1, col, matrix, memo);
    int downRight = dfs(n, row + 1, col + 1, matrix, memo);
    int downLeft = dfs(n, row + 1, col - 1, matrix, memo);

    // return the minimum sum of the three possible paths
    int minPath = min({directDown, downRight, downLeft});

    // store the solution to the subproblem in the memoization table
    return memo[row][col] = matrix[row][col] + minPath;
}

int minFallingPathDSum(vector<vector<int>>& matrix){
    int n = matrix.size();
    vector<vector<int>> memo(n, vector<int>(n,-1));
    int minsum = INT_MAX;
    for(int i=0;i<n;++i){
        minsum = min(minsum, dfs(n,0 , i, matrix, memo));
    }
    return minsum;
}

/**
 * @brief This function takes a 2D matrix of integers as input and returns the minimum sum of a falling path from the top
 * row to the bottom row. A falling path is a path that starts at the top row and ends at the bottom row, and each step
 * moves one cell down and one cell to the left, right, or directly down.
 *
 * @param matrix A 2D vector of integers, where matrix[i][j] represents the value at the i-th row and j-th column.
 *
 * @return The minimum sum of a falling path from the top row to the bottom row.
 */
int minFallingPathSumDP(vector<vector<int>>& matrix){
    int n = matrix.size();
    // Create a 1D array dp to store the minimum sum of a falling path from the top row to the current row.
    vector<int> dp(n);

    // Initialize the dp array with the values from the bottom row.
    dp = matrix[n - 1];

    // Iterate from the second to last row to the first row.
    for(int i = n-2;i >= 0;--i){
        // Create a temporary array cur to store the minimum sum of a falling path from the top row to the current row.
        vector<int> cur(n);

        // Iterate over each column of the current row.
        for(int j = 0;j < n;++j){
            // Calculate the minimum sum of a falling path from the top row to the current cell.
            int down = dp[j]; // Down direction
            int diagLeft = (j > 0) ? dp[j-1] : INT_MAX; // Diagonal left direction
            int diagRight = (j < n-1) ? dp[j + 1] : INT_MAX; // Diagonal right direction

            // Store the minimum sum in the temporary array cur.
            cur[j] = matrix[i][j] + min({down, diagLeft, diagRight});
        }

        // Update the dp array with the temporary array cur.
        dp = cur;
    }

    // Return the minimum sum of a falling path from the top row to the bottom row.
    return *min_element(dp.begin(), dp.end());
}

int main(){
    int n = 3;
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };

    cout << "Minimum falling path sum: " << minFallingPathDSum(matrix) << endl;
    cout << "Minimum falling path sum DP: " << minFallingPathSumDP(matrix);
    
    return 0;
}