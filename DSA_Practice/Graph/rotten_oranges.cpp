#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// Function to calculate the minimum time required to rot all fresh oranges
int rottenOranges(vector<vector<int>>& grid) {
    // Get the number of rows and columns in the grid
    int rows = grid.size();
    int cols = grid[0].size();
    // Initialize time taken to rot all oranges and count of fresh oranges
    int time = 0;
    int fresh = 0;

    // Queue to store the coordinates of rotten oranges
    queue<pair<int, int>> q;

    // Traverse the grid to count fresh oranges and enqueue rotten ones
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                // Count the number of fresh oranges
                fresh++;
            } else if (grid[i][j] == 2) {
                // Enqueue the initial rotten oranges
                q.push({i, j});
            }
        }
    }

    // Directions array to move up, down, left, and right
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Process the grid while there are fresh oranges and the queue is not empty
    while (fresh && !q.empty()) {
        // Get the number of rotten oranges in the current layer
        int len = q.size();
        // Process all rotten oranges in the current layer
        for (int i = 0; i < len; ++i) {
            // Get the current rotten orange's position
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Check all four possible directions from the current rotten orange
            for (auto& d : dirs) {
                int new_r = row + d[0];
                int new_c = col + d[1];

                // If the adjacent orange is fresh, rot it and enqueue its position
                if (new_r >= 0 && new_r < rows &&
                    new_c >= 0 && new_c < cols &&
                    grid[new_r][new_c] == 1) {
                    grid[new_r][new_c] = 2;         // Rot the orange
                    fresh--;                        // Decrement the number of fresh oranges
                    q.push({new_r, new_c});         // Enqueue the new rotten orange
                }
            }
        }

        // Increment time after processing one layer of rotten oranges
        // This represents the time taken for one round of rotting
        time++;
    }

    // If there are no fresh oranges left, return the time taken; otherwise, return -1
    return fresh == 0 ? time : -1;
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
    vector<vector<int>> grid = {{2,1,1},
                                {1,1,0},
                                {0,1,1}};
    print(grid);
    cout << rottenOranges(grid) << "\n";
    print(grid);
    return 0;
}