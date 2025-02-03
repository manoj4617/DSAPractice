#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * This function takes a string x and returns the length of the longest
 * palindromic subsequence in x.
 *
 * The function first reverses the original string and stores it in a new string
 * cpy. This is done because the longest common subsequence of x and cpy is
 * equivalent to the longest palindromic subsequence of x.
 *
 * The function then creates a 2D array dp of size (n+1) x (n+1), where dp[i][j]
 * is the length of the longest common subsequence between the first i characters
 * of x and the first j characters of cpy.
 *
 * The outer loop iterates over the elements of x, and the inner loop iterates
 * over the elements of cpy. For each pair of elements, the function checks if
 * the elements are equal. If they are, the function updates the dp array at the
 * current index to be one more than the value at the previous index. If they
 * are not equal, the function sets the dp array at the current index to be the
 * maximum of the two options: either including the current element of x in the
 * common subsequence, or not including the current element of x in the common
 * subsequence.
 *
 * Finally, the function returns dp[n][n], which is the length of the longest
 * common subsequence between x and cpy, which is equivalent to the length of the
 * longest palindromic subsequence of x.
 */
int LongestPalindromicSubSeq(string& x){
    //first reverse the original string
    string cpy = x;
    reverse(cpy.begin(), cpy.end());
    int n = x.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(x[i - 1] == cpy[j - 1]){
                //If the current elements of x and cpy are equal, then we have a
                //choice: either include the current element of x in the
                //subsequence, or not include the current element of x in the
                //subsequence. If we include the current element of x in the
                //subsequence, then the length of the subsequence is one more than
                //the length of the subsequence between the first i-1 characters
                //of x and the first j-1 characters of cpy.
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                //If the current elements of x and cpy are not equal, then we
                //have two options: either include the current element of x in
                //the subsequence, or not include the current element of x in the
                //subsequence. The function sets the dp array at the current index
                //to be the maximum of the two options.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    //Finally, the function returns dp[n][n], which is the length of the longest
    //common subsequence between x and cpy, which is equivalent to the length of
    //the longest palindromic subsequence of x.
    return dp[n][n];
}

int main(){
    string x;
    cin >> x;
    cout << LongestPalindromicSubSeq(x);
    return 0;
}