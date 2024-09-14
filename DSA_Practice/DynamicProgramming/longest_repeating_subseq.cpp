#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a string s as input and returns the length of the longest
 * repeating subsequence in s.
 *
 * The function uses a dynamic programming approach to solve the problem. It
 * creates a 2D vector dp of size (n+1) x (n+1), where dp[i][j] is the length of
 * the longest repeating subsequence in the first i characters of s and the
 * first j characters of s.
 *
 * The outer loop iterates over the elements of s, and the inner loop iterates
 * over the elements of s in reverse order. For each pair of elements, the
 * function checks if the elements are equal and if the current element is not
 * the same as the previous element. If both conditions are true, the function
 * sets dp[i][j] to be one more than the value at the previous index. If the
 * conditions are not true, the function sets dp[i][j] to be the maximum of the
 * two options: either including the current element in the repeating
 * subsequence, or not including the current element in the repeating
 * subsequence.
 *
 * Finally, the function returns dp[n][n], which is the length of the longest
 * repeating subsequence in s.
 */
int LongestRepeatingSubSeq(string& s){
    int n = s.size();
    if(n == 0) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1,0));

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(s[i - 1] == s[j - 1] && i != j){
                // If the current elements of s are equal and the current element
                // is not the same as the previous element, then we have a
                // repeating subsequence.
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                // If the conditions are not true, then we have two options: either
                // include the current element in the repeating subsequence, or
                // not include the current element in the repeating subsequence.
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}

int main(){
    string s;
    cin >> s;
    cout << "Longest repeating sub-sequence: " << LongestRepeatingSubSeq(s) << "\n";
    return 0;
}