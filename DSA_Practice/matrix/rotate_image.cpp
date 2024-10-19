#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Rotate an image represented as a matrix 90 degrees clockwise.
 *
 * This algorithm works by looping through the matrix in a spiral fashion,
 * swapping the elements at each step.  This is done by looping through the
 * rows and columns of the matrix, starting from the top left and moving
 * right, then down, then left, then up.
 *
 * At each step, the elements are swapped in the following order:
 *  - top left with top right
 *  - top right with bottom right
 *  - bottom right with bottom left
 *  - bottom left with top left
 *
 * This has the effect of rotating the matrix 90 degrees clockwise.
 */
void rotate_matrix(vector<vector<int>>& mat){
    int n = mat.size();

    // loop through the matrix in a spiral fashion
    for(int row = 0;row < n/2;row++){
        for(int col = row; col < n - row - 1; col++){
            // swap top left with top right
            swap(mat[row][col], mat[col][n - 1 - row]);

            // swap top right with bottom right
            swap(mat[row][col], mat[n - 1 - row][n - 1 - col]);

            // swap bottom right with bottom left
            swap(mat[row][col], mat[n - 1 - col][row]);
        }
    }
}


void printMat(const vector<vector<int>>& mat){
    for(auto& r : mat){
        for(const int& c : r){
            cout << c << " ";
        }
        cout << "\n";
    }
}

int main(){

    vector<vector<int>> matrix = {{6, 9}, {2, 7}};
    printMat(matrix);
    cout << "\n";
    rotate_matrix(matrix);
    printMat(matrix);
    return 0;
}