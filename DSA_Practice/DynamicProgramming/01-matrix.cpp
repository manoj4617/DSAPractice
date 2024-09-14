#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a 2D matrix of integers as input and returns a modified version of the matrix.
 * The modification is that for each cell in the matrix that contains a zero, the value of the cell is
 * changed to be the minimum distance from that cell to any cell containing a one.
 *
 * The algorithm works by first iterating over the matrix in row-major order, and for each cell that
 * contains a zero, it checks the cells above and to the left of the current cell for a one. If a one is
 * found, the value of the current cell is set to the minimum distance from the current cell to the one.
 *
 * After the first pass, the algorithm iterates over the matrix again, this time in column-major order.
 * For each cell that contains a zero, it checks the cells below and to the right of the current cell for
 * a one. If a one is found, the value of the current cell is set to the minimum distance from the current
 * cell to the one, or the existing value of the cell, whichever is smaller.
 *
 * The algorithm uses two passes over the matrix to ensure that the value of each cell is set to the
 * minimum distance from that cell to any cell containing a one.
 */
vector<vector<int>> ZeroOneMatrix(vector<vector<int>> &mat){
    int m = mat.size();     //rows
    int n = mat[0].size();  //columns

    // First pass: iterate over the matrix in row-major order
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            // If the current cell contains a zero, check the cells above and to the left for a one
            if(mat[i][j] == 0){
                int top = (i > 0) ? mat[i - 1][j] : INT_MAX - 10000;
                int left = (j > 0) ? mat[i][j - 1] : INT_MAX - 10000;
                mat[i][j] = min(top, left) + 1;
            }
        }
    }

    // Second pass: iterate over the matrix in column-major order
    for(int i=m-1;i>=0;--i){
        for(int j=n-1;j>=0;--j){

            // If the current cell contains a zero, check the cells below and to the right for a one
            if(mat[i][j] == 0){
                int bottom = (i < m - 1) ? mat[i+1][j] : INT_MAX - 10000;
                int right = (j < n - 1) ? mat[i][j+1] : INT_MAX - 10000;
                int dist = min(bottom, right) + 1;
                mat[i][j] = min(mat[i][j],dist);
            }
        }
    }

    return mat;
}

void PrintMatrix(const vector<vector<int>> &mat){
    int m = mat.size();     //rows
    int n = mat[0].size();  //columns
    for(int i=0;i<m;i++){
        for(int j=0;j<n;++j){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    std::vector<std::vector<std::vector<int>>> input_bits = {
        {{0, 1}, {1, 1}},
        {{0, 0, 1}, {0, 1, 1}, {1, 0, 1}},
        {{0, 0, 0}, {0, 1, 0}, {1, 0, 1}},
        {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}},
        {{0, 1, 0, 1}, {1, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}
    };

    for (int i = 0; i < input_bits.size(); i++) {
        std::cout << i + 1 << ".\t Input matrix:" << std::endl;
        PrintMatrix(input_bits[i]);
     

        std::vector<std::vector<int>> updatedMatrix = ZeroOneMatrix(input_bits[i]);

        std::cout << "\n\t Distance matrix:" << std::endl;
        PrintMatrix(updatedMatrix);
      
        std::cout << "-" << std::string(100, '-') << std::endl;
    }
}