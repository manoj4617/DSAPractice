#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * This function takes two strings x and y and returns the shortest common
 * super-sequence between the two strings. The function uses a dynamic
 * programming approach to solve the problem.
 *
 * The function first finds the longest common subsequence (LCS) of x and y by
 * creating a 2D array dp of size (m+1) x (n+1), where dp[i][j] is the length of
 * the LCS between the first i characters of x and the first j characters of y.
 *
 * The function then backtracks from the bottom right of the dp array to the top
 * left to construct the shortest common super-sequence of x and y. When the
 * current characters of x and y are equal, the function adds the character to
 * the result string and moves diagonally up and to the left. When the current
 * characters are not equal, the function adds the character of x or y to the
 * result string depending on whether the length of the LCS of the first i-1
 * characters of x and the first j characters of y is greater than the length of
 * the LCS of the first i characters of x and the first j-1 characters of y. If
 * the length of the LCS of the first i-1 characters of x and the first j
 * characters of y is greater, the function adds the character of x to the
 * result string and moves up. If the length of the LCS of the first i characters
 * of x and the first j-1 characters of y is greater, the function adds the
 * character of y to the result string and moves left.
 *
 * Finally, the function adds any remaining characters of x or y to the result
 * string and returns the result string.
 */
string ShortestCommonSubSeq(string &x, string &y, int m, int n){
    //Find LCS first
    vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));

    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(x[i - 1] == y[j - 1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << "super sequence length: " << (m + n) - dp[m][n] << "\n";
    string res;
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(x[i - 1] == y[j - 1]){
            res.push_back(x[i - 1]);
            i--;
            j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]){
            res.push_back(x[i - 1]);
            i--;
        }
        else{
            res.push_back(y[j - 1]);
            j--;
        }
    }

    while(i > 0){
        res.push_back(x[i - 1]);
        i--;
    }

    while(j > 0){
        res.push_back(y[j - 1]);
        j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string x , y;
    cin >> x >> y;
    cout << ShortestCommonSubSeq(x,y,x.length(), y.length());
    return 0;
}