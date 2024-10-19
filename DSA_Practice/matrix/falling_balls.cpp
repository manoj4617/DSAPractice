#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a 2D vector of integers representing a grid of balls
 * and returns a vector of integers representing the final resting position
 * of each ball in the grid. The grid is of size m x n, where m is the number
 * of rows and n is the number of columns. The value at each cell in the grid
 * represents the direction in which the ball at that cell will fall. A ball
 * at a cell with value 1 will fall to the right, and a ball at a cell with
 * value -1 will fall to the left. If a ball falls off the grid, it does not
 * affect the final resting position of any other balls.
 *
 * The algorithm works by looping through each column of the grid, and for
 * each column, it follows the path of the ball until it either falls off the
 * grid or reaches a cell with a different direction. If the ball reaches the
 * bottom of the grid without falling off, its final resting position is
 * recorded in the result vector.
 *
 * @param grid A 2D vector of integers representing the grid of balls.
 * @return A vector of integers representing the final resting position of
 * each ball in the grid.
 */
vector<int> WhereWillBallsFall(vector<vector<int>>& grid){
    vector<int> res(grid[0].size(), -1);
    int m = grid.size();
    int n = grid[0].size();

    // loop through each column of the grid
    for(int col = 0;col < n ; col++){
        int currentCol = col;

        // loop through each row of the grid
        for(int row = 0; row < m; row++){
            // calculate the next column index of the ball
            int nextCol = currentCol + grid[row][currentCol];

            // check if the ball has fallen off the grid or has reached a
            // cell with a different direction
            if(nextCol < 0 || nextCol > n - 1 || grid[row][nextCol] != grid[row][currentCol]){
                break;
            }

            // if the ball has reached the bottom of the grid without falling
            // off, record its final resting position in the result vector
            if(row == m - 1){
                res[col] = nextCol;
            }

            // move to the next column
            currentCol = nextCol;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> grid = {
        {-1, -1, -1, -1}, {1, 1, 1, 1}, {-1, -1, -1, -1}, {1, 1, 1, 1}
    };
    vector<int> res = WhereWillBallsFall(grid);
    for(int& num : res){
        cout << num << " ";
    }
    return 0;
}