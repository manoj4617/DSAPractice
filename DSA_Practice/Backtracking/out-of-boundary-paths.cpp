#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;
/**
 * This function calculates the number of paths that can be taken from the starting point (i, j)
 * to the boundary of the grid in N moves. The function takes the following parameters:
 *   m: The number of rows in the grid
 *   n: The number of columns in the grid
 *   N: The number of moves available
 *   i: The current row index
 *   j: The current column index
 *   memo: A 3D vector to store the results of subproblems
 *
 * The function returns the number of paths that can be taken from the starting point to the boundary
 * of the grid in N moves.
 */
int findAllPaths(int m, int n, int N, int i, int j, 
    vector<vector<vector<int>>>& memo){
    // Base case: If the current cell is out of bounds, return 1
    if(i == m || j == n || i < 0 || j < 0){
        return 1;
    }
    // Base case: If there are no more moves available, return 0
    if(N == 0) return 0;
    // If the current subproblem has already been solved, return the stored solution
    if(memo[i][j][N] >= 0){
        return memo[i][j][N];
    }
    // Calculate the number of paths that can be taken from the current cell to the boundary
    // of the grid in N moves by recursively calling the function on the four adjacent cells
    // (up, down, left, right) with one less move available.
    int paths = (
        ((findAllPaths(m,n,N-1,i+1,j,memo) + findAllPaths(m,n,N-1,i-1,j,memo)) % MOD) + 
        ((findAllPaths(m,n,N-1,i,j+1,memo) + findAllPaths(m,n,N-1,i,j-1,memo)) % MOD) 
    ) % MOD;
    // Store the result of the current subproblem in the memoization table
    memo[i][j][N] = paths;
    // Return the result of the current subproblem
    return memo[i][j][N];
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> memo(m,vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
    return findAllPaths(m, n, maxMove,  startRow, startColumn,memo);
}

int main(){
    int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
    cout << findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}