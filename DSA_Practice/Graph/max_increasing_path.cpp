#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
/**
 * This is a Depth-First Search (DFS) function that takes four parameters as an argument.
 * The first parameter is the row index of the current cell, the second parameter is the
 * column index of the current cell, the third parameter is a 2D vector of integers
 * representing the grid, and the fourth parameter is a 2D vector of integers that is used
 * to store the length of the longest increasing path from each cell to any other cell in
 * the grid.
 *
 * The function first checks if the length of the longest increasing path from the current
 * cell to any other cell in the grid is already stored in the memoization table. If it
 * is, the function returns the value stored in the table.
 *
 * If the length of the longest increasing path from the current cell to any other cell in
 * the grid is not stored in the memoization table, the function starts a DFS traversal
 * from the current cell to all its neighbors. The neighbors of the current cell are the
 * cells that are directly above, below, to the left, or to the right of the current cell.
 *
 * For each neighbor of the current cell, the function checks if the neighbor is within
 * the bounds of the grid and if the value of the neighbor is greater than the value of the
 * current cell. If the neighbor is within the bounds of the grid and its value is greater
 * than the value of the current cell, the function calls itself recursively on the
 * neighbor and adds 1 to the returned value. This is because the longest increasing path
 * from the current cell to the neighbor is 1 more than the longest increasing path from
 * the neighbor to any other cell in the grid.
 *
 * The function then stores the length of the longest increasing path from the current cell
 * to any other cell in the grid in the memoization table and returns the value.
 */
int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo){
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxLength = 1;

    for(auto d : dirs){
        int x = i + d[0];
        int y = j + d[1];

        if(x >= 0 && y >= 0 && x < rows && y < cols &&
           matrix[x][y] > matrix[i][j]){
             maxLength = max(maxLength,1 + dfs(x,y,matrix, memo));
           }
    }

    return memo[i][j] = maxLength;
}
// time complexity: O(m*n)
// space complexity: O(m*n)
int longestIncreasingPath(vector<vector<int>>& matrix) {
    // Return 0 immediately if the matrix is empty
    if (matrix.size() == 0) return 0;

    // Get number of rows and columns in the matrix
    int m = matrix.size();
    int n = matrix[0].size();

    // Create a memoization table to store the longest increasing path from each cell
    // Initialize all values to -1 indicating that no cell has been processed yet
    vector<vector<int>> memo(m, vector<int>(n, -1));

    // Variable to keep track of the maximum length of the increasing path found
    int count = 0;

    // Iterate over each cell in the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // For each cell, calculate the longest increasing path starting from that cell
            // Update the count with the maximum value found so far
            count = max(count, dfs(i, j, matrix, memo));
        }
    }

    // Return the maximum length of increasing path found in the matrix
    return count;
}


int main(){
    vector<vector<int>> matrix = {
        {3,4,5},
        {3,2,6},
        {2,2,1}};

    cout << longestIncreasingPath(matrix);
    return 0;
}