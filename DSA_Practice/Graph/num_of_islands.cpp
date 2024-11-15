#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Perform a depth-first search on the grid to mark all connected land ('1') as water ('0')
void dfs(vector<vector<char>> &grid, int i, int j) {
    // Get the number of rows and columns in the grid
    int row = grid.size();
    int col = grid[0].size();

    // Base case: If the current position is out of bounds or water, return
    if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') {
        return;
    }

    // Mark the current land cell as visited by setting it to water
    grid[i][j] = '0';

    // Define the four possible directions to explore: up, down, left, right
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Explore each direction
    for (auto &d : dirs) {
        // Calculate the new row and column based on the current direction
        int new_r = i + d[0];
        int new_c = j + d[1];

        // Recursively apply DFS to the neighboring cell
        dfs(grid, new_r, new_c);
    }
}

/**
 * Performs a breadth-first search on the grid to mark all connected land ('1') as water ('0')
 *
 * @param grid The 2D vector of characters representing the grid
 * @param i The row index of the starting point
 * @param j The column index of the starting point
 */
void bfs(vector<vector<char>>& grid, int i, int j){
    int rows = grid.size();
    int cols = grid[0].size();

    // Create a queue to keep track of the points to visit
    queue<pair<int,int>> toVisit;

    // Add the starting point to the queue
    toVisit.push({i,j});

    // Mark the starting point as visited (water)
    grid[i][j] = '0';

    // Define the four possible directions to explore: up, down, left, right
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Loop through the queue until it is empty
    while(!toVisit.empty()){
        // Get the next point to visit from the queue
        auto& [row, col] = toVisit.front();

        // Remove the point from the queue
        toVisit.pop();

        // Loop through each of the four directions
        for(auto& d : dirs){
            // Calculate the new row and column based on the current direction
            int new_r = row + d[0];
            int new_c = col + d[1];

            // If the new point is within the bounds of the grid and is land ('1'),
            // mark it as visited (water) and add it to the queue
            if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && grid[new_r][new_c] == '1'){
                grid[new_r][new_c] = '0';
                toVisit.push({new_r,new_c});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int numOfIslands = 0;
    int row = grid.size();
    if (row == 0)
        return 0;
    int col = grid[0].size();

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == '1')
            {
                numOfIslands++;
                dfs(grid, i, j);
                // bfs(grid,i,j);
            }
        }
    }
    return numOfIslands;
}

int main()
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid);

    return 0;
}