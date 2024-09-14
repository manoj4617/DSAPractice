#include <iostream>

using namespace std;

int LongestCommonSubstr(string& x, string& y, int m, int n){
    int dp[m + 1][n + 1];

    for(int i=0;i<=m;++i){
        for(int j=0;j<=n;++j){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    int res = 0;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(x[i - 1] == y[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res , dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int main(){
    string x , y;
    cin >> x >> y;
    cout << LongestCommonSubstr(x,y,x.length(), y.length());
    return 0;
}