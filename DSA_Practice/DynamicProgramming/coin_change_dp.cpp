#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a set of coins and a total amount of money as input and
 * returns the minimum number of coins that must be used to reach the total
 * amount of money. If it is not possible to reach the total amount of money
 * using the given set of coins, the function returns -1.
 *
 * The function uses a dynamic programming approach to solve the problem. It
 * creates a 2D vector of integers, where the number of rows is equal to the
 * size of the input set of coins, and the number of columns is equal to the
 * total amount of money plus one.
 *
 * The matrix is used to store the solutions to subproblems of the original
 * problem. The value at row i and column j of the matrix is the minimum number
 * of coins that must be used to reach the amount j using the first i coins of
 * the set.
 *
 * The function then iterates over the matrix in a bottom-up manner, solving
 * each subproblem in terms of the solutions to smaller subproblems. For each
 * subproblem, it checks if the current coin is less than or equal to the
 * current target amount. If it is, it checks if the solution to the subproblem
 * that excludes the current coin exists in the matrix. If it does, it sets
 * the current value in the matrix to be the minimum of the solution to the
 * subproblem that excludes the current coin and the solution to the subproblem
 * that includes the current coin plus one. If the solution to the subproblem
 * that excludes the current coin does not exist in the matrix, it sets the
 * current value in the matrix to be the solution to the subproblem that
 * includes the current coin plus one.
 *
 * If the current coin is not less than or equal to the current target amount,
 * the function sets the current value in the matrix to be the solution to the
 * subproblem that excludes the current coin.
 *
 * Finally, it returns the value at the bottom-right corner of the matrix, which
 * is the minimum number of coins that must be used to reach the total amount of
 * money.
 */
int CoinChange(vector<int>& coins, int total){
    int n = coins.size();
    vector<vector<int>> t(n + 1, vector<int>(total + 1, INT_MAX - 1));

    // Initialize the first row of the matrix to zero, since there is always a
    // solution that uses zero coins to reach the target amount of zero.
    for(int i=0;i<= n;++i){
        t[i][0] = 0;
    }

    // Iterate over the matrix in a bottom-up manner, solving each subproblem
    // in terms of the solutions to smaller subproblems.
    for(int i = 1; i <= n  ; ++i){
        for(int j = 1; j<= total ;++j){
            if(coins[i - 1] <= j){
                // If the current coin is less than or equal to the current
                // target amount, check if the solution to the subproblem that
                // excludes the current coin exists in the matrix. If it does,
                // set the current value in the matrix to be the minimum of the
                // solution to the subproblem that excludes the current coin and
                // the solution to the subproblem that includes the current coin
                // plus one. If the solution to the subproblem that excludes the
                // current coin does not exist in the matrix, set the current
                // value in the matrix to be the solution to the subproblem that
                // includes the current coin plus one.
                t[i][j]  = min(t[i - 1][j], t[i][j - coins[i -1 ]] + 1);
            }
            else{
                // If the current coin is not less than or equal to the current
                // target amount, set the current value in the matrix to be the
                // solution to the subproblem that excludes the current coin.
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // Return the value at the bottom-right corner of the matrix, which is the
    // minimum number of coins that must be used to reach the total amount of
    // money. If the value is equal to INT_MAX - 1, return -1 to indicate that
    // it is not possible to reach the total amount of money using the given
    // set of coins.
    return t[n][total] == INT_MAX - 1 ? -1 : t[n][total];
}

/**
 * This function takes a vector of integers, coins, and an integer total as
 * input, and returns the number of ways to make change for the given total
 * using the given set of coins.
 *
 * The function uses a dynamic programming approach to solve the problem. The
 * approach is to create a 2D matrix dp of size (n+1) x (total+1), where dp[i][j]
 * is the number of ways to make change for the amount j using the first i
 * coins.
 *
 * The outer loop iterates over each coin, starting from the first coin.
 * The inner loop iterates over each possible amount from 1 to total, starting
 * from the smallest amount.
 *
 * For each pair of coin and amount, the function checks if the coin is less
 * than or equal to the amount. If it is, the function calculates the number of
 * ways to make change for the amount by either including the current coin in
 * the subset or not including the current coin in the subset. The number of
 * ways is the sum of the number of ways to make change for the amount using the
 * first i-1 coins and the number of ways to make change for the amount minus the
 * current coin using the first i coins.
 *
 * If the coin is not less than or equal to the amount, the function sets dp[i][j]
 * to be dp[i-1][j], which is the number of ways to make change for the amount
 * using the first i-1 coins.
 *
 * Finally, the function returns dp[n][total], which is the number of ways to
 * make change for the total amount using all the coins.
 */
int coin_change_count(vector<int>& coins, int total){
    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int>(total + 1));
    for(int i=0;i<=n;++i){
        for(int j=0;j<=total;++j){
            if(i == 0){
                // If the current coin is the first coin, then the number of
                // ways to make change for the amount is 0, since there is only
                // one way to make change for 0.
                dp[i][j] = 0;
            }
            if(j == 0){
                // If the amount is 0, then the number of ways to make change for
                // the amount is 1, since there is only one way to make change
                // for 0.
                dp[i][j] = 1;
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=total;++j){
            if(coins[i-1] <= j){
                // If the current coin is less than or equal to the amount, then
                // we have two options: either include the current coin in the
                // subset, or not include the current coin in the subset. The
                // number of ways is the sum of the number of ways to make change
                // for the amount using the first i-1 coins and the number of
                // ways to make change for the amount minus the current coin
                // using the first i coins.
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
            }
            else{
                // If the current coin is not less than or equal to the amount,
                // then the number of ways to make change for the amount is the
                // same as the number of ways to make change for the amount using
                // the first i-1 coins.
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Return the number of ways to make change for the total amount using all
    // the coins.
    return dp[n][total];
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
    // cout << CoinChange(coins, total);
    cout << coin_change_count(coins,total);
    return 0;
}