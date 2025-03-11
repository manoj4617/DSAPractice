#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Recursive function with memoization to count arrangements
/*
 * This function takes in the following parameters:
 *   n: the total number of sticks
 *   k: the number of sticks that are visible from the left
 *   dp: a memoization table to store the results of subproblems
 *
 * The function returns the number of ways to arrange the sticks such that
 * exactly k sticks are visible from the left.
 */
int dfs(int n, int k, vector<vector<int>>& dp){
    // Base case: if n sticks and k visible, there's exactly 1 way (all sticks in increasing order)
    if(n == k)
        return 1;
    // Base case: if no sticks or no visible sticks, there's no valid arrangement
    if(n == 0 || k == 0)
        return 0;

    if(dp[n][k] != -1)
        return dp[n][k];

    // Recurrence relation:
    // 1. Place the tallest stick at the end, then solve for (n-1, k-1)
    // 2. Place the tallest stick somewhere else, then solve for (n-1, k) and multiply by (n-1) positions
    /*
     * The recurrence relation is derived from the fact that the tallest stick can be placed at the end of the arrangement
     * or somewhere in the middle. If it is placed at the end, then the problem reduces to solving for (n-1, k-1)
     * (since the tallest stick will not block any other sticks). If it is placed in the middle, then the problem reduces
     * to solving for (n-1, k) and then multiplying the result by (n-1) (since there are (n-1) positions where the tallest
     * stick can be placed without blocking any other sticks).
     */
    dp[n][k] = (dfs(n-1,k-1, dp) + (long long)(n-1) * dfs(n-1,k,dp) % MOD) % MOD;
    return dp[n][k]; 
}
int rearrangeSticks(int n, int k) {
    // vector<vector<int>> dp(n + 1, vector<int>(k+1, -1));
    // return dfs(n,k,dp);
        
    vector<vector<int>> dp(n + 1, vector<int>(k+1, 0));
    dp[1][1] = 1;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=k;++j){
            dp[i][j] = (dp[i-1][j-1] + (long long)(i-1) * dp[i-1][j]) % MOD;
        }
    }
    return dp[n][k];
}

int main(){
    int n = 5, k = 2;

    cout << "Number of arrangements: " << rearrangeSticks(n, k) << endl;
    return 0;
}