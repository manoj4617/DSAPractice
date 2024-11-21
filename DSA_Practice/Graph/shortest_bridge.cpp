#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int,int>> bfs_queue;

void printGrid(vector<vector<int>>& grid){
    int r = grid.size();
    int c = grid[0].size();

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout << grid[i][j] << " ";
        }
        cout  << "\n";
    }
}
/**
 * Performs a depth-first search on the grid from the given position (x,y) and
 * marks all connected land ('1') as visited ('2').
 *
 * @param grid The 2D vector of integers representing the grid.
 * @param x The row index of the current position.
 * @param y The column index of the current position.
 */
void dfs(vector<vector<int>>& grid, int x, int y){
    int rows = grid.size();
    int cols = grid[0].size();

    // Mark the current land cell as visited by setting it to 2
    grid[x][y] = 2;

    // Add the current position to the queue so that we can perform BFS from here
    bfs_queue.push({x,y});

    // Explore all four connected neighbors of the current cell
    for(int i=0;i<4;++i){
        int new_row = x + dirs[i][0];
        int new_col = y + dirs[i][1];

        // If the new position is within the grid and is land (1), then we need to visit it
        if(0 <= new_row && 0 <= new_col && new_row < rows && new_col < cols && grid[new_row][new_col] == 1){
            // Recursively call the depth-first search function from the new position
            dfs(grid,new_row, new_col);
        } 
    }
}

/**
 * This function takes a 2D vector of integers and returns the shortest distance
 * (in terms of the number of steps) between two islands in the grid.
 *
 * The function first finds the position of one of the islands by traversing the
 * grid and finding the first occurrence of a 1 (land). This is the starting
 * position for the breadth-first search.
 *
 * The breadth-first search is implemented using a queue. The queue is used to
 * keep track of all the points that need to be visited. The search starts from
 * the starting position and explores all the neighboring points in all four
 * directions. If a neighbor is a 1 (land), it means that the search has reached
 * the other island and the function returns the current distance.
 *
 * If a neighbor is a 0 (water), it is added to the queue and marked as visited
 * by setting its value to -1. The search continues until all points have been
 * visited and the shortest distance is returned.
 */
int shotestBridge(vector<vector<int>>& grid){
    int rows = grid.size();
    int cols = grid[0].size();

    // Find the position of one of the islands
    int x = -1, y = -1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;++j){
            if(grid[i][j] == 1){
                x = i;
                y = j;
                break;
            }
        }
    }

    cout  << "Initial grid: " << "\n";
    printGrid(grid);
    // Perform a depth-first search to mark all connected land as visited
    dfs(grid, x, y);

    cout << "Grid after finding first islands: " << "\n";
    printGrid(grid);

    // Initialize the distance to 0
    int dist = 0;
    int k = 0;
    // Perform a breadth-first search to find the shortest distance to the other
    // island
    while(!bfs_queue.empty()){
        // Create a new queue to store the points to visit in the next iteration
        queue<pair<int,int>> new_q;

        // Get the number of points in the current queue
        int len = bfs_queue.size();
        cout << "Grid after " << k << " layer of searching: \n";
        printGrid(grid);
        // Loop through all the points in the current queue
        for(int i=0;i<len;++i){
            // Get the current point from the queue
            int row = bfs_queue.front().first;
            int col = bfs_queue.front().second;
            bfs_queue.pop();

            // Loop through all four directions
            for(int i=0;i<4;++i){
                // Calculate the new row and column based on the current direction
                int new_row = row + dirs[i][0];
                int new_col = col + dirs[i][1];

                // Check if the new point is within the bounds of the grid
                if(0 <= new_row && 0 <= new_col && new_row < rows && new_col < cols){
                    // If the new point is a 1 (land), it means that the search has
                    // reached the other island and the function returns the current
                    // distance
                    if(grid[new_row][new_col] == 1){
                        return dist;
                    }

                    // If the new point is a 0 (water), add it to the new queue and
                    // mark it as visited
                    else if(grid[new_row][new_col] == 0){
                        new_q.push({new_row,new_col});
                        grid[new_row][new_col] = -1;
                    }
                }
            }
        }

        // Update the queue for the next iteration
        bfs_queue = new_q;

        // Increment the distance by 1
        dist++;
        k++;
    }

    // Return the shortest distance
    return dist;
}

int main(){
    // vector<vector<int>> grid ={
    //     {1,1,1,1,1},
    //     {1,0,0,0,1},
    //     {1,0,1,0,1},
    //     {1,0,0,0,1},
    //     {1,1,1,1,1}
    // };

    vector<vector<int>> grid ={
        {0,1,0},
        {0,0,0},
        {0,0,1}
    };

    cout << shotestBridge(grid);
    return 0;
}