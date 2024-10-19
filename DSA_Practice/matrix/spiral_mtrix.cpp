#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a matrix and returns a vector which contains the elements
 * of the matrix in the order they would appear if the matrix were traversed in
 * a spiral pattern.
 *
 * The algorithm works by keeping track of its current position in the matrix
 * and the direction in which it should move. The direction is determined by
 * the value of the variable 'direction', which is either 1 (for right) or -1
 * (for left). The algorithm moves as far as it can in the current direction,
 * then changes direction and moves as far as it can in the new direction.
 *
 * The algorithm keeps track of the number of rows and columns that it has
 * traversed, and it continues until it has traversed all of the rows and
 * columns in the matrix.
 */
vector<int> Spiral_matrix(vector<vector<int>>& matrix){
    vector<int> res;

    int direction = 1;
    int row = 0, col = -1;

    int m = matrix.size();
    int n = matrix[0].size();

    // loop through the matrix until all of the rows and columns have been
    // traversed
    while(m > 0 && n > 0){

        // move to the right
        for(int i=0;i<n;++i){
            col += direction;
            res.push_back(matrix[row][col]);
        }
        m--; // reduce the number of rows to traverse

        // move down
        for(int i=0;i<m;++i){
            row += direction;
            res.push_back(matrix[row][col]);
        }
        n--; // reduce the number of columns to traverse

        // reverse direction
        direction *= -1;
    }
    return res;
}

int main(){
    
     vector<vector<int>> matrix = {
        {10, 1, 14, 11, 14},
        {13, 4, 8, 2, 13},
        {10, 19, 1, 6, 8},
        {20, 10, 8, 2, 12},
        {15, 6, 8, 8, 18}
    };

    vector<int> res = Spiral_matrix(matrix);
    for(int& num : res){
        cout << num << " ";
    }
    return 0;
}