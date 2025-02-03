#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function implements the dynamic programming approach to solve the
 *        "Best Time to Buy and Sell Stock IV" problem. The problem is to find the
 *        maximum profit that can be obtained by buying and selling a stock at most
 *        k times, given a vector of prices.
 *
 * @param i The current index in the prices vector.
 * @param k The number of transactions left to make.
 * @param holding A boolean indicating whether we are currently holding a stock
 *                or not.
 * @param prices A vector of integers representing the prices of the stock at
 *               each time step.
 * @param memo A 3-dimensional vector to store the maximum profit that can be
 *             obtained by considering the first i items, making k transactions,
 *             and holding or not holding a stock.
 *
 * @return An integer representing the maximum profit that can be obtained by
 *         making k transactions and holding or not holding a stock.
 */
int dp(int i, int k , int holding, vector<int>& prices, vector<vector<vector<int>>>& memo){
    /**
     * Base case: if we have reached the end of the prices vector or if we have
     *            used up all the transactions, then return 0.
     */
    if(i == prices.size() || k == 0){
        return 0;
    }

    /**
     * If we have already computed the maximum profit for the current
     * subproblem, then return it from the memo table.
     */
    if(memo[i][k][holding] != -1){
        return memo[i][k][holding];
    }

    /**
     * Calculate the maximum profit that can be obtained by doinog nothing
     * and moving to the next time step.
     */
    int doNothing = dp(i + 1, k, holding, prices, memo);

    /**
     * Calculate the maximum profit that can be obtained by buying or selling
     * a stock at the current time step. If we are currently holding a stock,
     * then we can sell it. Otherwise, we can buy it.
     */
    int buyOrSell;
    if(holding){
        // if hoding a stock we can sell it or do nothing
        buyOrSell = prices[i] + dp(i + 1, k-1, 0,prices,memo);
    }
    else{
        // if not hoding a stock we can buy it or do nothing
        buyOrSell = -prices[i] + dp(i + 1, k, 1,prices,memo);
    }

    /**
     * Store the maximum profit that can be obtained by considering the first
     * i items, making k transactions, and holding or not holding a stock.
     */
    return memo[i][k][holding] = max(doNothing, buyOrSell);
}

int maxProfit(int k , vector<int> prices){
    vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(k + 1, vector<int>(2,-1)));
    return dp(0,k,0,prices,memo);
}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int k = 2;
    int n = prices.size();
    cout << maxProfit(k, prices);
    return 0;
}