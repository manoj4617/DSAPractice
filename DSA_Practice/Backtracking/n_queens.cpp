#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * Checks if a queen can be placed at a given position on the board.
 * The checks are done by iterating over all the previously placed queens.
 * For each previous queen, the following checks are done:
 * 1. Do the new and old queens have the same column?
 * 2. Is the new queen on the same diagonal as the old queen?
 * If any of the above conditions are true, it means that the new queen can't
 * be placed at the given position, and the function returns false.
 * Otherwise, the function returns true.
 *
 * @param new_row The row index of the new queen.
 * @param new_col The column index of the new queen.
 * @param solution A vector that stores the positions of all the previously
 * placed queens. The i-th element of the vector stores the column index of
 * the queen at the i-th row.
 * @return True if the new queen can be placed at the given position, false
 * otherwise.
 */
bool isValidMove(int new_row, int new_col, vector<int>& solution){
    int old_row = 0, old_col = 0, diagonal = 0;
    for(int i=0;i<new_row;++i){
        // Get the row and column index of the old queen
        old_row = i;
        old_col = solution[i];

        // Calculate the diagonal distance between the new and old queens
        diagonal = new_row - old_row;

        // Check if the new and old queens have the same column
        if( old_col == new_col ) {
            return false;
        }

        // Check if the new queen is on the same diagonal as the old queen
        if( old_col == new_col + diagonal ||
            old_col == new_col - diagonal) {
            return false;
        }
        // The reason we can use the difference between new_row and old_row
        // to check if the new queen is on the same diagonal as the old queen
        // is because the difference between the row indices is always equal
        // to the difference between the column indices of two points on the
        // same diagonal. For example, if the new queen is at (3, 3) and
        // the old queen is at (1, 1), then the difference between the row
        // indices is 2, which is the same as the difference between the
        // column indices (3 - 1 = 2). This is true for all diagonals in
        // an n x n chessboard. Therefore, if the difference between the
        // row indices of the new and old queens is equal to the difference
        // between their column indices, then the new queen is on the same
        // diagonal as the old queen.
    }
    // If all the checks pass, the new queen can be placed at the given position
    return true;
}

/**
 * This function uses backtracking to generate all possible placements of
 * n queens on an n x n chessboard such that no queen can attack another.
 *
 * @param state_space A vector that stores all the possible placements of
 * the queens found so far.
 * @param solution A vector that stores the positions of all the previously
 * placed queens. The i-th element of the vector stores the column index of
 * the queen at the i-th row.
 * @param n The size of the chessboard.
 * @param row The current row index being processed.
 */
void Backtrack(vector<vector<int>>& state_space, vector<int>& solution, int n, int row){
    // Base case: if all the queens have been placed, add the current solution
    // to the state space and return.
    if(row == n){
        state_space.push_back(solution);
        return;
    }

    // Iterate over all the possible column indices that the queen at the
    // current row can be placed at.
    for(int i=0;i<n;++i){
        // Check if the queen can be placed at the current column index.
        if(isValidMove(row, i, solution)){
            // If the queen can be placed, set the column index of the queen
            // at the current row to the current column index.
            solution[row] = i;

            // Recurse with the next row.
            Backtrack(state_space, solution, n, row + 1);
        }
    }
}

int NQueens(int n){
    vector<vector<int>> state_space;
    vector<int> solution(n,-1);
    Backtrack(state_space, solution, n,0);
    for(auto& sol : state_space){
        for(int& c : sol)
            cout << c << " ";
        cout << "\n";
    }
    return state_space.size();
}

int main(){
    int n;
    cin >> n;
    cout << NQueens(n);
    return 0;
}