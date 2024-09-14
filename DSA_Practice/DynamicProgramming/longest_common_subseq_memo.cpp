#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes two strings x and y and returns the length of the longest
 * common subsequence between the two strings. The function uses a memoization
 * approach to store the results of subproblems and reuse them to avoid
 * redundant computation.
 *
 * The function takes an additional parameter, memo, which is a 2D vector of
 * integers. The memo vector is used to store the results of subproblems. The
 * element at memo[i][j] represents the length of the longest common subsequence
 * between the substring x[0..i-1] and the substring y[0..j-1]. If the element
 * at memo[i][j] is -1, it means that the subproblem has not been solved yet.
 *
 * The function first checks if the subproblem has already been solved by
 * checking if the element at memo[n-1][m-1] is not -1. If it is not -1, the
 * function returns the value at memo[n-1][m-1] directly.
 *
 * If the subproblem has not been solved yet, the function checks if the last
 * characters of the two strings are equal. If they are equal, the function adds
 * 1 to the longest common subsequence between the substrings excluding the
 * last characters (i.e. LongestCommonSubSeqMemo(x, y, m - 1, n - 1, memo)).
 *
 * If the last characters are not equal, the function returns the maximum of the
 * longest common subsequence between the substrings excluding the last
 * character of x (i.e. LongestCommonSubSeqMemo(x, y, m, n - 1, memo)) and the
 * longest common subsequence between the substrings excluding the last
 * character of y (i.e. LongestCommonSubSeqMemo(x, y, m - 1, n, memo)).
 */
int LongestCommonSubSeqMemo(string& x, string& y, int m, int n, vector<vector<int>>& memo){
    // Base case: if either string is empty, the longest common subsequence is 0
    if(n == 0 || m == 0){
        return 0;
    }

    // If the subproblem has already been solved, return the result directly
    if(memo[m][n] != -1){
        return memo[m][n];
    }

    // If the last characters of the two strings are equal, add 1 to the longest
    // common subsequence between the substrings excluding the last characters
    if(x[m - 1] == y[n - 1]){
        memo[m][n] = 1 + LongestCommonSubSeqMemo(x, y, m - 1, n - 1, memo);
        return memo[m][n];
    }
    // If the last characters are not equal, return the maximum of the longest
    // common subsequence between the substrings excluding the last character of
    // x and the longest common subsequence between the substrings excluding the
    // last character of y
    else{
        int lcs1 = LongestCommonSubSeqMemo(x, y, m, n - 1, memo);
        int lcs2 = LongestCommonSubSeqMemo(x, y, m - 1, n, memo);
        memo[m][n] = max(lcs1, lcs2);
        return memo[m][n];
    }
}

int main(){
    string x , y;
    cin >> x >> y;
    vector<vector<int>> memo(x.length() + 1, vector<int>(y.length() + 1, -1));
    cout << LongestCommonSubSeqMemo(x,y,x.length(), y.length(), memo);
    return 0;
}