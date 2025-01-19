#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * @brief This function takes a 2D vector of integers as an argument and returns
 * the maximum distance from a land cell to a water cell in the grid.
 *
 * @details
 * This function implements a breadth-first search (BFS) algorithm to find the
 * maximum distance from a land cell to a water cell in the grid. The search
 * starts from all land cells in the grid and explores all of its neighboring
 * cells in all four directions (up, down, left, right). The algorithm uses a
 * queue to keep track of the cells that need to be visited. The queue is
 * initialized with all of the land cells in the grid. The algorithm then enters
 * a loop where it pops the next cell from the queue, marks all of its
 * unvisited neighbors as visited and adds them to the queue, and updates the
 * maximum distance with the current distance if the current cell is a water
 * cell. The algorithm continues until all cells have been visited.
 *
 * @param[in] grid A 2D vector of integers representing the grid.
 *
 * @return The maximum distance from a land cell to a water cell in the grid.
 */
int maxDistance(vector<vector<int>>& grid) {
    // Create a queue to keep track of the cells to visit
    queue<pair<int,pair<int,int>>> q;

    // Get the number of rows in the grid
    int n = grid.size();

    // Loop through the grid and add all land cells to the queue
    for(int i=0; i<n;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j] == 1){
                // Add the land cell to the queue
                q.push({0,{i,j}});
            }
        }
    }

    // Check if there are no land cells or all cells are land cells
    if(q.size() == 0 || q.size() == n * n){
        // If there are no land cells or all cells are land cells, return -1
        return -1;
    }

    // Directions to move in the grid.
    // The first element of the pair is the row offset and the second element is
    // the column offset.
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    // Initialize the maximum distance to INT_MIN
    int maxDist = INT_MIN;

    // Loop until the queue is empty
    while(!q.empty()){
        // Get the length of the queue
        int len = q.size();

        // Loop through all of the cells in the queue
        for(int i=0;i<len;++i){
            // Get the current cell from the queue
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            // Remove the current cell from the queue
            q.pop();

            // Explore all of the neighbors of the current cell
            for(auto& dir : dirs){
                int newR = row + dir[0];
                int newC = col + dir[1];

                // Check if the new cell is within the bounds of the grid and is
                // not marked as visited before
                if(newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 0){
                    // Mark the new cell as visited with the current distance
                    grid[newR][newC] = dist + 1;

                    // Add the new cell to the queue
                    q.push({grid[newR][newC], {newR, newC}});
                }
            }
        }
    }

    // Loop through all of the cells in the grid and update the maximum distance
    for(int i=0;i<n;++i){
        maxDist = max(maxDist, *max_element(grid[i].begin(), grid[i].end()));
    }

    // Return the maximum distance
    return maxDist;
}


int main(){
    vector<vector<int>> grid = {    {1,0,0,0},
                                    {0,0,0,0},
                                    {0,0,0,0},
                                    {0,0,0,1}};
    cout << maxDistance(grid) << endl;
    return 0;
}