#include <vector>
#include <iostream>

using namespace std;

/**
 * This function takes two integers, m and n, and returns the number of unique
 * paths from the top-left of an m x n grid to the bottom-right of the grid.
 *
 * The function uses a dynamic programming approach to solve the problem. It
 * creates a 2D vector dp of size m x n, where dp[i][j] is the number of unique
 * paths from the top-left to the current cell (i,j) of the grid.
 *
 * The function first initializes the dp array to 0, and then sets the first row
 * and first column of dp to 1, since there is only one way to reach each cell
 * in the first row and first column.
 *
 * The function then iterates over the dp array in a bottom-up manner, solving
 * each subproblem in terms of the solutions to smaller subproblems. For each
 * subproblem, it adds the number of unique paths from the cell above and the
 * cell to the left to the current cell.
 *
 * Finally, the function returns dp[m-1][n-1], which is the number of unique
 * paths from the top-left to the bottom-right of the grid.
 */
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Set the first row and first column of dp to 1, since there is only one
    // way to reach each cell in the first row and first column.
    for(int i=0;i<m;++i){
        dp[i][0] = 1;
    }
    for(int j=0;j<n;++j){
        dp[0][j] = 1;
    }

    // Iterate over the dp array in a bottom-up manner, solving each subproblem
    // in terms of the solutions to smaller subproblems.
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    // Return the number of unique paths from the top-left to the bottom-right
    // of the grid.
    return dp[m-1][n-1];
}

int main(){
    int m,n;;
    cin >> m >> n;
    cout << "Unique paths: " << uniquePaths(m,n);
    return 0;
}