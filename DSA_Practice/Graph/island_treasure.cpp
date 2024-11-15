#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

/**
 * This is a depth-first search (DFS) function that takes a 2D vector of integers
 * representing a grid, and two coordinates (i, j) as an argument. The function
 * also takes a distance parameter, which is the minimum distance from the
 * starting point that the current cell must be in order to be considered for
 * exploration.
 *
 * The function first checks if the starting point is within the bounds of the
 * grid and if the cell at the starting point is not marked as an obstacle (-1)
 * and if the cell at the starting point is not already marked as visited with
 * a distance that is less than the given distance. If the cell at the starting
 * point does not satisfy these conditions, the function returns without doing
 * anything.
 *
 * If the starting point is within the bounds of the grid and is not marked as
 * an obstacle or visited before, the function marks the current cell as
 * visited with the given distance, and recursively calls itself on all four
 * directions (up, down, left, right) from the current cell.
 *
 * The function does not return anything, so it is declared as void.
 */
void dfs(vector<vector<int>>& grid, int i, int j, int dist){
    // Check if the starting point is within the bounds of the grid
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
        return;
    }

    // Get the number of rows and columns in the grid
    int rows = grid.size();
    int cols = grid[0].size();

    // Check if the cell at the starting point is not marked as an obstacle (-1)
    if(grid[i][j] == -1){
        return;
    }

    // Check if the cell at the starting point is not already marked as visited
    // with a distance that is less than the given distance
    if(grid[i][j] < dist){
        return;
    }

    // Mark the current cell as visited with the given distance
    grid[i][j] = dist;

    // Recursively call this function on all four directions (up, down, left, right)
    // from the current cell
    for(auto& d : dirs){
        dfs(grid, i + d[0], j + d[1], dist + 1);
    }
}

/**
 * @brief Performs a breadth-first search on the grid to mark all connected
 * cells as visited with the given distance.
 *
 * @details
 * This function takes a 2D vector of integers and two coordinates (i, j) as an
 * argument. It performs a breadth-first search of the grid starting from the
 * given coordinates. It uses a queue to keep track of the nodes to visit. It
 * marks the starting point as visited with the given distance, and then enters
 * a loop where it pops the next node from the queue, marks it as visited with
 * the given distance plus one, and then adds all of its unvisited neighbors to
 * the queue. It repeats this process until it has visited all nodes in the
 * queue.
 *
 * @param[in,out] grid A 2D vector of integers representing the grid.
 * @param[in] i The row index of the starting point.
 * @param[in] j The column index of the starting point.
 */
void bfs(vector<vector<int>>& grid, int i, int j){
    int rows = grid.size();
    int cols = grid[0].size();

    // Create a queue to keep track of the nodes to visit
    queue<pair<int, int>> q;

    // Add the starting point to the queue
    q.push({i, j});

    // Loop until the queue is empty
    while(!q.empty()){
        // Get the next point from the queue
        int row = q.front().first;
        int col = q.front().second;

        // Remove the point from the queue
        q.pop();

        // Explore all of the neighbors of the current point
        for(auto& d : dirs){
            int new_r = row + d[0];
            int new_c = col + d[1];

            // Check if the new point is within the bounds of the grid and is
            // not marked as an obstacle (-1) and is not already marked as
            // visited with a distance that is less than the given distance plus
            // one
            if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols &&
                grid[new_r][new_c] != -1 && grid[new_r][new_c] > grid[row][col] + 1){
                // Mark the current cell as visited with the given distance plus
                // one
                grid[new_r][new_c] = grid[row][col] + 1;

                // Add the new point to the queue
                q.push({new_r, new_c});
            }
        }
    }
}

void islandsAndTreasure(vector<vector<int>> &grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 0){
                // dfs(grid, i, j,0);
                bfs(grid, i, j);
            }
        }
    }
}

void print(vector<vector<int>> grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int>> grid = {
        {INT_MAX - 1,-1,0,INT_MAX - 1},
        {INT_MAX - 1,INT_MAX - 1,INT_MAX - 1,-1},
        {INT_MAX - 1,-1,INT_MAX - 1,-1},
        {0,-1,INT_MAX - 1,INT_MAX - 1}
    };
    print(grid);
    islandsAndTreasure(grid);
    print(grid);
    return 0;
}