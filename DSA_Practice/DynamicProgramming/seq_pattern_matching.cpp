#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes two strings x and y and returns a boolean indicating
 * whether or not y contains a sequence pattern of x.
 *
 * The function first finds the longest common subsequence (LCS) between the two
 * strings. The LCS is stored in a 2D array dp of size (m+1) x (n+1), where dp[i][j]
 * is the length of the LCS between the first i characters of x and the first j
 * characters of y.
 *
 * The function then checks if the LCS is equal to the length of either of the
 * two strings. If it is, then the LCS is a sequence pattern in the other string,
 * and the function returns true. Otherwise, the function returns false.
 */
int SeqPatternMatching(string &x, string &y){
    int m = x.length();
    int n = y.length();

    //find LCS among both the strings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            // If the current elements of x and y are equal, then we have two
            // options: either include the current element of x in the LCS of the
            // substrings x[0..i-1] and y[0..j-1], or not include the current
            // element of x in the LCS of the substrings x[0..i-1] and y[0..j-1].
            if(x[i-1] == y[j-1]){
                // If we include the current element of x in the LCS, then the
                // length of the LCS is one more than the length of the LCS of the
                // substrings x[0..i-2] and y[0..j-2].
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                // If we do not include the current element of x in the LCS, then
                // the length of the LCS is the maximum of the two options.
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    //if the LCS is equal to any of the original string it means the LCS is a sequence
    //pattern in the other string
    return min(n,m) == dp[m][n];
}

int main(){
    string x,y;
    cin >> x >> y;
    cout << "Pattern Matching? " << SeqPatternMatching(x,y);
    return 0;
}