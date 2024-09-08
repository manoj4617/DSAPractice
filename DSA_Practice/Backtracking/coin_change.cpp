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
 * @param i The current index in the given set of coins.
 * @param count The current count of coins that we have used.
 * @param minCoins The minimum number of coins that we have found so far.
 */
void Backtrack(const vector<int>& coins, int total, int i, int count, int& minCoins){
    // The base case: if the current total is zero, we have found a valid
    // combination of coins, so we update the minimum number of coins that we
    // have found so far. We use the minimum of the current count of coins and
    // the minimum number of coins that we have found so far because we want to
    // find the minimum number of coins that sum up to the target amount.
    if(total == 0){
        minCoins = min(count, minCoins);
        return;
    }

    // If the current total is negative or if we have reached the end of the
    // given set of coins, we have reached a dead end, so we return.
    if(total < 0 || i == coins.size()){
        return;
    }

    // If the current coin is less than or equal to the current total, we can
    // include it in the current combination of coins and recurse with the
    // updated total and the next index in the set of coins.
    if(coins[i] <= total){
        Backtrack(coins, total - coins[i], i, count + 1, minCoins);
    }

    // We can also exclude the current coin from the current combination of
    // coins and recurse with the next index in the set of coins. This is the
    // case where we don't use the current coin, so we don't increment the count
    // of coins.
    Backtrack(coins, total, i + 1, count, minCoins);

}


int CoinChange(vector<int>& coins, int total){
    int minCoins = INT_MAX;
    Backtrack(coins,total,0,0, minCoins);
    return minCoins != INT_MAX ? minCoins : -1;
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