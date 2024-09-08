#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a set of integers and a target number as input, and
 * returns true if there exists a subset of the given set of integers that sum
 * up to the target number, and false otherwise.
 *
 * The function uses a dynamic programming approach to solve the problem. It
 * creates a 2D vector of boolean values, where the number of rows is equal to
 * the size of the input set, and the number of columns is equal to the target
 * number plus one.
 *
 * The matrix is used to store the solutions to subproblems of the original
 * problem. The value at row i and column j of the matrix is true if there
 * exists a subset of the first i integers of the set that sums up to j, and
 * false otherwise.
 *
 * The function then iterates over the matrix in a bottom-up manner, solving
 * each subproblem in terms of the solutions to smaller subproblems. For each
 * subproblem, it checks if the current number is less than or equal to the
 * current target value. If it is, it checks if the solution to the subproblem
 * that excludes the current number exists in the matrix. If it does, it sets
 * the current value in the matrix to true. If not, it sets it to false.
 *
 * Finally, it returns the value at the bottom-right corner of the matrix, which
 * is the solution to the original problem.
 */
int Subset_sumDP(vector<int>& set, int target){
    vector<vector<bool>> t(set.size(), vector<bool>(target + 1));

    // Initialize the first row of the matrix to true, since there is always a
    // subset of the first i integers that sums up to 0.
    for(int i=0;i<set.size();++i){
        t[i][0] = true;
    }

    // Initialize the first column of the matrix to false, since there is no
    // subset of the first i integers that sums up to a number greater than
    // the target.
    for(int i=1;i<target + 1;++i){
        t[0][i] = false;
    }

    // Iterate over the matrix in a bottom-up manner, solving each subproblem
    // in terms of the solutions to smaller subproblems.
    for(int i=1;i<set.size() + 1;++i){
        for(int j = 1; j < target + 1;++j){
            if(set[i - 1] <= j){
                // If the current number is less than or equal to the current
                // target value, check if the solution to the subproblem that
                // excludes the current number exists in the matrix.
                t[i][j] = t[i - 1][j - set[i - 1]] || t[i - 1][j];
            }
            else{
                // If the current number is greater than the current target
                // value, the solution to the subproblem is the same as the
                // solution to the subproblem that excludes the current number.
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // Return the value at the bottom-right corner of the matrix, which is the
    // solution to the original problem.
    return t[set.size()][target];
}

int main(){
    int n = 5;
    vector<int> a = {1, 5, 3, 7, 4};
    int sum = 12;

    if (Subset_sumDP(a, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}