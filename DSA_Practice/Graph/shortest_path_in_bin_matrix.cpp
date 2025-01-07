#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief This function takes a 2D vector of integers (a grid) as an argument and returns the shortest path from the top-left corner to the bottom-right corner in the grid.
 * The path can only be traversed through cells containing 0s and must avoid cells containing 1s.
 * The function returns the minimum number of steps required to traverse the grid from the top-left corner to the bottom-right corner.
 * If there is no path from the top-left corner to the bottom-right corner, the function returns -1.
 *
 * @param grid A 2D vector of integers representing the grid.
 *
 * @return The minimum number of steps required to traverse the grid from the top-left corner to the bottom-right corner.
 */
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            // If the top-left or bottom-right corner is a 1, there is no path from the top-left corner to the bottom-right corner.
            return -1;
        }
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        q.push({0,0});
        // Directions to move in the grid.
        // The first element of the pair is the row offset and the second element is the column offset.
        vector<vector<int>> dirs = {
            {1,0},{-1,0},
            {0,1},{0,-1},
            {1,1},{-1,1},
            {1,-1},{-1,-1}
        };
        int steps = 1;
        while(!q.empty()){
            int len = q.size();

            for(int i=0;i<len;++i){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r == n - 1 && c == n - 1){
                    // If the current cell is the bottom-right corner, return the number of steps to reach it.
                    return steps ;
                }

                // Loop through all of the directions and explore the neighboring cells.
                for(const auto& dir : dirs){
                    int new_r = r + dir[0];
                    int new_c = c + dir[1];

                    if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n
                        && grid[new_r][new_c] == 0 && !visited[new_r][new_c]){
                            // If the neighboring cell is not visited, mark it as visited and add it to the queue.
                            q.push({new_r,new_c});
                            visited[new_r][new_c] = true;
                        }
                }
            }
            // Increment the number of steps.
            steps++;
        }
        // If there is no path from the top-left corner to the bottom-right corner, return -1.
        return -1;
    }


int main(){
    vector<vector<int>> grid = {
        {0,0,0},
        {1,1,0},
        {1,1,0}
    };

    cout << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}