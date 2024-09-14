#include<iostream>
#include<vector>

using namespace std;

/**
 * Finds the maximum profit that can be made by buying and selling a stock
 * given a vector of prices. The profit is the difference between the
 * maximum price and the minimum price.
 *
 * The algorithm is to keep track of the maximum profit that can be made
 * by buying and selling a stock. The profit is the difference between the
 * maximum price and the minimum price. The algorithm iterates through the
 * vector of prices and for each price, it checks if the current profit is
 * greater than the maximum profit found so far. If it is, it updates the
 * maximum profit. If it is not, it does nothing.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int max_profit(vector<int> p){
    int max_profit = 0; // maximum profit that can be made
    int left = 0; // index of the leftmost price
    int right = 1; // index of the rightmost price
    int profit; // profit of buying and selling a stock

    // iterate through the vector of prices
    while(right < p.size()){

        // calculate the profit of buying and selling a stock
        profit = p[right] - p[left];

        // check if the current profit is greater than the maximum profit
        // found so far
        if(profit > max_profit){
            // update the maximum profit
            max_profit = profit;
        }

        // if the profit is not greater than the maximum profit, do nothing

        // increment the rightmost index
        right++;
    }

    // return the maximum profit that can be made
    return max_profit;
}

int main(){
    int n,temp;
    cin >> n;
    vector<int> p;
    for(int i=0;i<n;++i){
        cin >> temp;
        p.push_back(temp);
    }
    cout << max_profit(p);
}