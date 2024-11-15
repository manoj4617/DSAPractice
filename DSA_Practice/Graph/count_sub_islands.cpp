#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCellLand(int x , int y, vector<vector<int>>& grid){
    return grid[x][y] == 1;
}

/**
 * Checks if the island in grid2 is a sub-island of the island in grid1.
 *
 * @param grid1 The 2D vector representing the first grid.
 * @param grid2 The 2D vector representing the second grid.
 * @param visited A 2D vector of booleans that keeps track of the cells we've visited.
 * @param x The row index of the cell we're starting from.
 * @param y The column index of the cell we're starting from.
 *
 * @return True if the island in grid2 is a sub-island of the island in grid1, false otherwise.
 */
bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
                    vector<vector<bool>>& visited, int x, int y){
    /**
     * Get the number of rows and columns in grid2.
     */
    int rows = grid2.size();
    int cols = grid2[0].size();

    /**
     * Assume that the island in grid2 is a sub-island of the island in grid1.
     */
    bool is_sub_island = true;

    /**
     * Create a queue to keep track of the cells we need to visit.
     */
    queue<pair<int,int>> q;

    /**
     * Add the starting cell to the queue and mark it as visited.
     */
    q.push({x,y});
    visited[x][y] = true;

    /**
     * Define the four directions in which we can move.
     */
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    /**
     * Loop until we've visited all cells in the queue.
     */
    while(!q.empty()){
        /**
         * Get the next cell from the queue.
         */
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        /**
         * If the current cell is not land in grid1, then the island in grid2 is not a
         * sub-island of the island in grid1.
         */
        if(!isCellLand(row, col, grid1)){
            is_sub_island = false;
        }

        /**
         * Loop through each of the four directions.
         */
        for(auto& d : dirs){
            /**
             * Calculate the new row and column based on the current direction.
             */
            int new_r = row + d[0];
            int new_c = col + d[1];

            /**
             * If the new cell is within the bounds of the grid, is land in grid2, and
             * hasn't been visited yet, then mark it as visited and add it to the queue.
             */
            if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols &&
                !visited[new_r][new_c] && isCellLand(new_r,new_c, grid2)){
                    visited[new_r][new_c] = true;
                    q.push({new_r, new_c});
                }
        }
    }

    return is_sub_island;
}

// Function to count the number of sub-islands in grid2 that are also islands in grid1
int count_sub_islands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    // Get the number of rows and columns in grid2
    int rows = grid2.size();
    int cols = grid2[0].size();

    // Create a 2D vector to keep track of visited cells in grid2
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Initialize the count of sub-islands
    int numOfSubIslands = 0;

    // Iterate through each cell in grid2
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If the current cell in grid2 is land, not visited, and forms a sub-island
            if (!visited[i][j] && isCellLand(i, j, grid2) && isSubIsland(grid1, grid2, visited, i, j)) {
                // Increment the count of sub-islands
                numOfSubIslands++;
            }
        }
    }

    // Return the total number of sub-islands found
    return numOfSubIslands;
}

/**
 * This function iterates over each cell in grid2 to find sub-islands. A sub-island in grid2
 * is defined as an island that is entirely contained within an island in grid1. The function
 * checks each cell to see if it is land ('1'), has not been visited, and is part of a sub-island.
 * If these conditions are met, it uses the helper function isSubIsland to check if the island
 * in grid2 is also an island in grid1. If it is, the sub-island count is incremented.
 */

int main(){
    vector<vector<int>> grid1 = {   {1,1,1,0,0},
                                    {0,1,1,1,1},
                                    {0,0,0,0,0},
                                    {1,0,0,0,0},
                                    {1,1,0,1,1}};

    vector<vector<int>> grid2 = {   {1,1,1,0,0},
                                    {1,1,1,1,1},
                                    {0,0,0,0,0},
                                    {1,0,0,0,0},
                                    {1,1,0,1,1}};
    cout << count_sub_islands(grid1, grid2);
    return 0;
}