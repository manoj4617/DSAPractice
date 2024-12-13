#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a 2D vector of integers as input and returns the number of unique paths from the top-left of the grid to the bottom-right of the grid.
 * The function uses a dynamic programming approach to solve the problem. The approach is to create a 2D vector dp of size m x n, where dp[i][j] is the number of unique paths from the top-left to the current cell (i,j) of the grid.
 *
 * The function first checks if the starting position has an obstacle. If it does, the function returns 0.
 * The function then traverses the first row and first column of the grid, and for each cell, it checks if the cell has an obstacle (1). If the cell has an obstacle, the function sets the cell and the next cell to 1, since the next cell can't be travelled.
 *
 * The function then iterates over the dp array in a bottom-up manner, solving each subproblem in terms of the solutions to smaller subproblems. For each subproblem, it checks if the current cell has an obstacle (1). If the current cell does not have an obstacle, the function calculates the number of unique paths to the current cell by adding the number of unique paths to the cell above and the cell to the left. If the current cell has an obstacle, the function sets the number of unique paths to the current cell to 0.
 *
 * Finally, the function returns dp[m-1][n-1], which is the number of unique paths from the top-left to the bottom-right of the grid.
 */
int uniquePaths2(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // check if the starting position has an obstacle
    if(grid[0][0] == 1){
        return 0;
    }
    grid[0][0] = 1;

    // traverse first row
    // if any place has an obstacle (1)
    // set that place and the next place to 1
    // since the next place cant be travelled
    for(int i=1;i<m;++i){
        grid[i][0] = (grid[i][0] == 0 && grid[i-1][0] == 1) ? 1 : 0;  
    }

    //same for column
    for(int i=1;i<n;++i){
        grid[0][i] = (grid[0][i] == 0 && grid[0][i-1] == 1) ? 1 : 0;
    }

    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(grid[i][j] == 0){
                // calculate the number of unique paths to the current cell
                // by adding the number of unique paths to the cell above and
                // the cell to the left
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
            else{
                // if the current cell has an obstacle, set the number of unique
                // paths to the current cell to 0
                grid[i][j] = 0;
            }
        }
    }

    return grid[m - 1][n - 1];
}

int main(){
    vector<vector<int>> grid = {{0,0,0},
                                {0,1,0},
                                {0,0,0}};
    cout << uniquePaths2(grid);
    return 0;
}