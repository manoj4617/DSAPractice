#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LongestPalindromicSubSeq(string& x){
    //first reverse the original string
    string cpy = x;
    reverse(cpy.begin(), cpy.end());
    int n = x.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(x[i - 1] == cpy[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    string x;
    cin >> x;
    cout << LongestPalindromicSubSeq(x);
    return 0;
}