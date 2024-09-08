#include <iostream>
#include <vector>

using namespace std;

int CoinChange(vector<int>& coins, int total){
    int n = coins.size();
    vector<vector<int>> t(n + 1, vector<int>(total + 1, INT_MAX - 1));

    for(int i=0;i<= n;++i){
        t[i][0] = 0;
    }

    for(int i = 1; i <= n  ; ++i){
        for(int j = 1; j<= total ;++j){
            if(coins[i - 1] <= j){
                t[i][j]  = min(t[i - 1][j], t[i][j - coins[i -1 ]] + 1);
            }
            else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][total] == INT_MAX - 1 ? - 1 : t[n][total];
}

int main(){
    int n, total;
    cin >> n >> total;
    vector<int> coins(n);
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        coins.push_back(t);
    }
    cout << CoinChange(coins, total);
    return 0;
}