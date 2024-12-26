#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of stock prices and returns the maximum profit
 * that can be obtained by performing a series of buy and sell transactions.
 * The transactions are performed in a greedy manner, such that the function
 * iterates through the vector of prices and whenever it encounters a price
 * that is higher than the previous price, it adds the difference to the total
 * profit.
 *
 * The time complexity of this function is O(n), where n is the size of the
 * input vector. This is because the function iterates through the vector once
 * and performs a constant amount of work for each element.
 *
 * The space complexity of this function is O(1), since the function does
 * not use any additional space that scales with the size of the input vector.
 *
 * @param prices a vector of stock prices
 * @return the maximum profit that can be obtained by performing a series of
 *         buy and sell transactions
 */
int buySellStocks(vector<int>& prices){
    int profit = 0;
    int n = prices.size();
    for(int i=1;i<n;++i){
        if(prices[i] > prices[i-1]){
            /**
             * If the current price is greater than the previous price, then
             * we can make a profit by selling the stock at the current price
             * and buying it back at the previous price. The profit is the
             * difference between the two prices.
             */
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    cout << buySellStocks(prices);
    return 0;
}