#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * This function takes two strings x and y and returns the length of the longest
 * common subsequence between the two strings. The function uses a dynamic
 * programming approach to solve the problem.
 *
 * The dp array is used to store the maximum length of any common subsequence
 * between the substrings of x and y. dp[i][j] stores the maximum length of any
 * common subsequence between the substrings x[0..i-1] and y[0..j-1].
 *
 * The outer loop iterates over the elements of x, and the inner loop iterates
 * over the elements of y. For each pair of elements, the function checks if the
 * elements are equal. If they are, the function updates the dp array at the
 * current index to be one more than the value at the previous index. If they are
 * not equal, the function sets the dp array at the current index to be the
 * maximum of the two options: either including the current element of x in the
 * common subsequence, or not including the current element of x in the common
 * subsequence.
 *
 * Finally, the function returns dp[m][n], which is the maximum length of any
 * common subsequence between the two strings.
 */
int LongestCommonSubSeqDP(string& x, string& y, int m , int n){
    // Create a 2D array dp to store the maximum length of any common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Initialize the first row and first column of dp to 0
    for(int i = 0;i<=m;++i){
        for(int j = 0;j<=n;++j){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    // Iterate over the elements of x and y
    for(int i = 1;i<=m;++i){
        for(int j = 1;j<=n;++j){
            // If the current elements of x and y are equal, then we have two
            // options: either include the current element of x in the common
            // subsequence, or not include the current element of x in the common
            // subsequence.
            if(x[i-1] == y[i-1]){
                // If we include the current element of x in the common
                // subsequence, then the maximum length of the common subsequence
                // is one more than the maximum length of the common subsequence
                // between the substrings x[0..i-2] and y[0..j-2]
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                // If we don't include the current element of x in the common
                // subsequence, then the maximum length of the common subsequence
                // is the maximum of the two options: either including the current
                // element of x in the common subsequence, or not including the
                // current element of x in the common subsequence.
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    //Printing the subsequence
    int i = m, j = n;
    string str;
    while(i > 0 && j > 0){
        if(x[i - 1] == y[j - 1]){
            str.push_back(x[i - 1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j - 1] > dp[i - 1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(str.begin(), str.end());
    cout << str << "\n";
    // Return the maximum length of any common subsequence between the two strings
    return dp[m][n];
}

int main(){
    string x , y;
    cin >> x >> y;
    cout << LongestCommonSubSeqDP(x,y,x.length(), y.length());
    return 0;
}