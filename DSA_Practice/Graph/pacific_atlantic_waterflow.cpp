#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
     * Approach:
     * - This solution aims to identify cells on a grid where water can flow to both the Pacific and Atlantic oceans.
     * - Each cell has a height value, and water can only flow to a neighboring cell if it has an equal or lower height.
     * - The grid is bordered by the Pacific Ocean on the top and left, and by the Atlantic Ocean on the bottom and right.
     * 
     * Logic:
     * - Using Depth-First Search (DFS), we start from cells on the borders of each ocean and mark cells that can flow into each ocean.
     * - We use two sets (`pac` and `atl`) to track cells that can reach the Pacific and Atlantic oceans, respectively.
     * - Starting from each ocean's borders, we perform DFS in four directions to mark cells reachable from that ocean.
     * - If a cell is reachable from both oceans (present in both `pac` and `atl`), it is added to the result.
     * 
     * Reasoning:
     * - The key idea is to reverse the typical flow from each cell to the ocean by marking cells starting from each ocean.
     * - This allows us to determine if water can flow into each ocean using a DFS traversal from each ocean's boundary.
     * - This approach ensures that each cell is processed only once per ocean, making it efficient.
     */

    /**
     * DFS function to mark cells reachable from a given ocean.
     * Parameters:
     * - `x`, `y`: The current cell's row and column indices.
     * - `heights`: 2D grid representing the height map.
     * - `visit`: A set storing cells reachable by the current ocean.
     * - `prvHeight`: The height of the previous cell to ensure valid water flow.
     *
     * Logic:
     * - Check if the current cell is out of bounds, has a lower height than `prvHeight`, or has been visited.
     * - If any of these conditions are true, return from the function as water cannot flow to this cell.
     * - Otherwise, mark this cell as visited, then recursively call DFS in all four directions.
     */
void dfs(int x, int y, vector<vector<int>> &heights, set<pair<int, int>> &visit, int prvHeight)
{
    int rows = heights.size();
    int cols = heights[0].size();

    if (x < 0 || x >= rows || y < 0 || y >= cols ||
        heights[x][y] < prvHeight || visit.count({x, y}))
    {
        return;
    }
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    visit.insert({x, y});
    for (auto &d : dirs)
    {
        dfs(x + d[0], y + d[1], heights, visit, heights[x][y]);
    }
}

/**
     * Main function to find all cells where water can flow to both oceans.
     * Parameters:
     * - `heights`: 2D grid representing the height map of the island.
     *
     * Logic:
     * - Initialize two sets, `pac` and `atl`, to store cells reachable by the Pacific and Atlantic oceans, respectively.
     * - Perform DFS from all boundary cells touching the Pacific Ocean (top and left edges) and Atlantic Ocean (bottom and right edges).
     * - After marking reachable cells for both oceans, iterate through each cell to check if it can reach both oceans.
     * - If a cell is present in both `pac` and `atl`, add it to the result as it can flow to both oceans.
     *
     * Reasoning:
     * - By starting DFS from each ocean's boundary and moving inward, we avoid redundant checks and ensure efficient processing.
     */
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    set<pair<int, int>> pac, alt;

    for (int i = 0; i < cols; ++i)
    {
        dfs(0, i, heights, pac, heights[0][i]);                 // first row
        dfs(rows - 1, i, heights, alt, heights[rows - 1][i]);   // last row
    }

    for (int j = 0; j < rows; ++j)
    {
        dfs(j, 0, heights, pac, heights[j][0]);                 // first column
        dfs(j, cols - 1, heights, alt, heights[j][cols - 1]);   // last column
    }

    vector<vector<int>> res;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (pac.count({i, j}) && alt.count({i, j}))         // checking if the current cell is reachable by both oceans
            {
                res.push_back({i, j});
            }
        }
    }

    return res;
}

int main(){
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = pacificAtlantic(heights);
    for(auto &i : res){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}