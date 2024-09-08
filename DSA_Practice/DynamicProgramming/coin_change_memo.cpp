#include <climits>
#include <iostream>
#include <vector>

using namespace std;


/**
 * This function uses backtracking to generate all possible combinations of
 * coins that sum up to a given target amount.
 *
 * @param coins The given set of coins.
 * @param total The target amount that we want to reach.
 * @param memo A vector to store the minimum number of coins required to
 *             reach each subproblem. The vector is indexed by the amount of
 *             money that we want to reach, and the value at each index is the
 *             minimum number of coins required to reach that amount.
 *
 * @return The minimum number of coins required to reach the target amount.
 */
int Backtrack(const vector<int>& coins, int total, vector<int>& memo){
    // Base case: if the current total is zero, we have found a valid
    // combination of coins, so we return 0, which is the minimum number of
    // coins required to reach the target amount.
    if (total == 0) {
        return 0;
    }

    // If the current total is negative or if we have reached the end of the
    // given set of coins, we have reached a dead end, so we return
    // INT_MAX, which is the maximum number of coins that we can use.
    if (total < 0) {
        return INT_MAX;
    }

    // If the solution to the current subproblem has already been computed,
    // then return the solution.
    if (memo[total] != -1) {
        return memo[total];
    }

    // Initialize the minimum number of coins required to reach the current
    // subproblem to INT_MAX.
    int minCoins = INT_MAX;

    // Iterate over each coin in the given set of coins.
    for (const auto& c : coins) {
        // Recursively call Backtrack with the updated total and the current
        // coin as the next coin to consider.
        int res = Backtrack(coins, total - c, memo);

        // If the recursive call returns a valid solution (i.e., not INT_MAX),
        // then update the minimum number of coins required to reach the
        // current subproblem.
        if (res != INT_MAX) {
            minCoins = min(minCoins, res + 1);
        }
    }

    // Store the minimum number of coins required to reach the current
    // subproblem in the memo vector.
    memo[total] = minCoins;

    // Return the minimum number of coins required to reach the current
    // subproblem.
    return memo[total];
}


int CoinChange(vector<int>& coins, int total){
    vector<int> memo(total + 1, -1);
    int res = Backtrack(coins,total,memo);
    return res != INT_MAX ? res : -1;
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