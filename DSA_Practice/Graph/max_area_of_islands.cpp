#include <vector>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * This function takes a 2D vector of integers and two coordinates (i, j) as an argument.
 * It performs a breadth-first search of the grid starting from the given coordinates.
 * It marks all visited cells as 0 and returns the area of the island.
 *
 * @param grid A 2D vector of integers representing the grid.
 * @param i The row index of the starting point.
 * @param j The column index of the starting point.
 *
 * @return The area of the island if it exists, 0 otherwise.
 */
int bfs(vector<vector<int>> &grid, int i, int j)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int area = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = 0;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // loop through the queue until it is empty
    while(!q.empty()){
        auto& [row, col] = q.front();
        q.pop();

        // loop through each of the four directions
        for(auto& d : dirs){
            int new_r = row + d[0];
            int new_c = col + d[1];

            // if the new point is within the bounds of the grid and is a 1 (land),
            // mark it as visited (water) and add it to the queue
            if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && grid[new_r][new_c] == 1){
                area++;
                grid[new_r][new_c] = 0;
                q.push({new_r, new_c});
            }
        }
    }
    return area;
}

/**
 * This is a depth-first search (DFS) function that takes a 2D vector of integers
 * representing a grid and two indices i and j representing the starting point.
 * It marks all visited cells as 0 and returns the area of the island.
 *
 * The function first checks if the starting point is within the bounds of the
 * grid and if the cell at the starting point is a 1 (land). If the cell is a 0
 * (water), the function returns 0.
 *
 * If the cell is a 1, the function marks it as visited (water) and sets the area
 * to 1. It then recursively calls itself on all four directions (up, down, left,
 * right) from the current cell. If any of the recursive calls return a non-zero
 * value, it means that there is an island in that direction and the area of the
 * current island is increased by the value returned.
 *
 * Finally, the function returns the total area of the island.
 */
int dfs(vector<vector<int>>& grid, int i, int j){
    int rows = grid.size();
    int cols = grid[0].size();

    // check if the starting point is within the bounds of the grid and if the
    // cell at the starting point is a 1 (land)
    if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0){
        // if the cell is a 0 (water), return 0
        return 0;
    }

    int area = 1;
    // mark the current cell as visited (water)
    grid[i][j] = 0;

    // define the four directions in which we can move
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // loop through each of the four directions
    for(auto& d : dirs){
        // recursively call this function on the adjacent cell
        area += dfs(grid, i + d[0], j + d[1]);
    }

    // return the total area of the island
    return area;
}


int maxAreaOfIsland(vector<vector<int>> &grid)
{

    int rows = grid.size();
    int cols = grid[0].size();
    int maxArea = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                int area = bfs(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}

int main(){

    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout << maxAreaOfIsland(grid);
}