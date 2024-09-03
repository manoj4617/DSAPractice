#include <iostream>
#include <vector>

using namespace std;

/**
 * A helper function to perform a depth first search in a given grid to find all
 * the elements that have the same value as the source element.
 *
 * @param[in,out] grid A 2D vector of integers representing the grid.
 * @param[in] row The row index of the current cell being explored.
 * @param[in] col The column index of the current cell being explored.
 * @param[in] oldTarget The value of the source element.
 * @param[in] target The new value to replace the source element with.
 */
void DFS(vector<vector<int>>& grid, int row, int col, int oldTarget, int target){
    // get the number of rows and columns in the grid
    int grid_row = grid.size();
    int grid_col = grid[0].size();

    // define the four directions in which we can move
    vector<pair<int,int>> directions = {
        {0,1}, // right
        {1,0}, // down
        {-1,0}, // up
        {0,-1} // left
    };

    // loop through each direction in which we can move
    for(const auto& newDir : directions){
        // calculate the new row and column indices if we move in this direction
        int newRow = row + newDir.first;
        int newCol = col + newDir.second;

        // check if the new indices are within the bounds of the grid, and if
        // the element at the new position has the same value as the source
        // element
        if(newRow >= 0 && newRow < grid_row && newCol >= 0 && newCol < grid_col
            && grid[newRow][newCol] == oldTarget){
            // if the conditions are satisfied, replace the element at the new
            // position with the target value
            grid[newRow][newCol] = target;

            // recursively call this function on the new position
            DFS(grid,newRow, newCol, oldTarget, target);
        }
    }
}

vector<vector<int>> FloodFill(vector<vector<int>>& grid, int sr, int sc, int target){
    //if source element is already equal to the target return it
    if(grid[sr][sc] == target){
        return grid;
    }
    else{
        int oldTarget = grid[sr][sc];
        grid[sr][sc] = target;
        DFS(grid, sr,sc,oldTarget, target);
        return grid;
    }
}

void Print2DList(vector<vector<int>> grid){
    for(auto& r : grid){
        for(auto& c : r){
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
     // Input grid of grids
    std::vector<std::vector<std::vector<int>>> grids = {
                {{1, 1, 0, 1, 0}, 
                {0, 0, 0, 0, 1}, 
                {0, 0, 0, 1, 1}, 
                {1, 1, 1, 1, 0}, 
                {1, 0, 0, 0, 0}},

                {{1, 1, 0, 1}, 
                {0, 0, 0, 0}, 
                {0, 0, 0, 1}, 
                {1, 1, 1, 1}},

                {{9, 9, 6, 9}, 
                {6, 9, 9, 6}, 
                {6, 9, 9, 9}, 
                {9, 9, 9, 9}},

                {{1, 1, 0, 1}, 
                {0, 1, 0, 0}, 
                {0, 1, 1, 0}, 
                {1, 0, 1, 1}},
        
                {{1, 2, 0, 0}, 
                {3, 1, 3, 6}, 
                {7, 2, 1, 5}, 
                {1, 9, 2, 1}}
            };

    std::vector<int> sr = {4, 2, 2, 2, 1};
    std::vector<int> sc = {3, 3, 1, 3, 1};
    std::vector<int> target = {3, 2, 1, 0, 4};


    for (int i = 0; i < grids.size(); i++) {
		std::cout << i + 1 << ".\t Grid before flood fill: \n" ;
        Print2DList(grids[i]);
        std::cout << "\t Starting row and column are: (" << sr[i] << ", " << sc[i] << ")" << std::endl;
        std::cout << "\t Target value: " << target[i] << std::endl;
        std::vector<std::vector<int>> result = FloodFill(grids[i], sr[i], sc[i], target[i]);
        std::cout << "\t After perform flood fill: \n";
        Print2DList(result);
		std::cout << std::string(100,'-') << std::endl;
    }
}