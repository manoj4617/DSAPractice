#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a 2D vector of characters as input and returns the area of the largest square
 * that can be formed from the characters in the matrix.
 *
 * The function uses a dynamic programming approach to solve the problem. The dp array is used
 * to store the size of the largest square that can be formed from the characters in the matrix at
 * each position. The size of the largest square that can be formed from the characters in the matrix
 * at each position is the minimum of the sizes of the largest squares that can be formed from the
 * characters in the matrix at the positions above, to the left, and to the top-left of the current
 * position, plus one.
 *
 * The function iterates over the dp array in a bottom-up manner, solving each subproblem in terms
 * of the solutions to smaller subproblems. For each subproblem, it checks if the character in the
 * matrix at the current position is '1'. If the character is '1', the function calculates the size
 * of the largest square that can be formed from the characters in the matrix at the current position
 * by taking the minimum of the sizes of the largest squares that can be formed from the characters
 * in the matrix at the positions above, to the left, and to the top-left of the current position, and
 * adding one.
 *
 * Finally, the function returns the area of the largest square that can be formed from the characters
 * in the matrix, which is the maximum of the sizes of the largest squares that can be formed from the
 * characters in the matrix at each position, squared.
 */
int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = row > 0 ? matrix[0].size() : 0;

    // Create a 2D vector dp to store the size of the largest square that can be
    // formed from the characters in the matrix at each position.
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int area = 0;
    for(int i=1;i<=row;++i){
        for(int j=1;j<=col;++j){
            // Check if the character in the matrix at the current position is '1'.
            if(matrix[i - 1][j - 1] == '1'){
                // Calculate the size of the largest square that can be formed from
                // the characters in the matrix at the current position by taking
                // the minimum of the sizes of the largest squares that can be formed
                // from the characters in the matrix at the positions above, to the
                // left, and to the top-left of the current position, and adding one.
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                // Update the maximum area of the largest square that can be formed
                // from the characters in the matrix at each position.
                area = max(area, dp[i][j]);
            }
        }
    }
    // Return the area of the largest square that can be formed from the characters
    // in the matrix, which is the maximum of the sizes of the largest squares that
    // can be formed from the characters in the matrix at each position, squared.
    return area * area;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                  {'1','0','1','1','1'},
                                  {'1','1','1','1','1'},
                                  {'1','0','0','1','0'}};  
    cout << maximalSquare(matrix) << endl;
    return 0; 
}