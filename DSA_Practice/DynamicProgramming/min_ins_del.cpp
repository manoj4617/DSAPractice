#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes two strings x and y and returns the minimum number of
 * insertion and deletion operations required to transform x into y.
 *
 * The function uses a dynamic programming approach to solve the problem. The
 * dp array is used to store the length of the longest common subsequence (LCS)
 * between the substrings x[0..i-1] and y[0..j-1].
 *
 * The outer loop iterates over the elements of x, and the inner loop iterates
 * over the elements of y. For each pair of elements, the function checks if the
 * elements are equal. If they are, the function updates the dp array at the
 * current index to be one more than the value at the previous index. If they are
 * not equal, the function sets the dp array at the current index to be the
 * maximum of the two options: either including the current element of x in the
 * LCS of the substrings x[0..i-1] and y[0..j-1], or not including the current
 * element of x in the LCS of the substrings x[0..i-1] and y[0..j-1].
 *
 * Finally, the function returns the minimum number of insertion and deletion
 * operations required to transform x into y, which is the difference between the
 * lengths of the two strings minus twice the length of the LCS between the two
 * strings.
 */
int MinInsDel(string& x, string& y, int m, int n){
    // Create a 2D array dp to store the length of the LCS between the substrings
    // of x and y.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));

    // Iterate over the elements of x and y.
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            // If the current elements of x and y are equal, then we have two
            // options: either include the current element of x in the LCS of the
            // substrings x[0..i-1] and y[0..j-1], or not include the current
            // element of x in the LCS of the substrings x[0..i-1] and y[0..j-1].
            if(x[i - 1] == y[j - 1]){
                // If we include the current element of x in the LCS, then the
                // length of the LCS is one more than the length of the LCS of the
                // substrings x[0..i-2] and y[0..j-2].
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                // If we do not include the current element of x in the LCS, then
                // the length of the LCS is the maximum of the two options: either
                // including the current element of x in the LCS of the substrings
                // x[0..i-1] and y[0..j-1], or not including the current element of
                // x in the LCS of the substrings x[0..i-1] and y[0..j-1].
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return the minimum number of insertion and deletion operations required to
    // transform x into y.
    int operations = (m - dp[m][n]) + (n - dp[m][n]);
    return operations;
}


int main(){
    string x , y;
    cin >> x >> y;
    cout << MinInsDel(x,y,x.length(), y.length());
    return 0;
}