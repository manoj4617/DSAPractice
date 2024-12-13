#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Rotate an image represented as a matrix 90 degrees clockwise using transpose
 * and reverse methods.
 *
 * The transpose function works by swapping the elements of the matrix such that
 * the element at position [i][j] is swapped with the element at position [j][i].
 *
 * The reverse function works by reversing the elements of each row in the
 * matrix.
 *
 * By first transposing the matrix and then reversing each row, the matrix is
 * rotated 90 degrees clockwise.
 */
void printMat(const vector<vector<int>>& mat){
    for(auto& r : mat){
        for(const int& c : r){
            cout << c << " ";
        }
        cout << "\n";
    }
}
void transpose(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

}
void reverse(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

void rotate_matrix(vector<vector<int>>& mat){
    transpose(mat);
    // printMat(mat);
    reverse(mat);
}



int main(){

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    printMat(matrix);
    cout << "\n";
    rotate_matrix(matrix);
    printMat(matrix);
    return 0;
}