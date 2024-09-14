#include <iostream>
#include <vector>

using namespace  std;

/**
 * @brief This function takes an integer len and a vector of integers prices as input, and returns
 *        the maximum value that can be obtained by cutting the rod of length len into pieces
 *        of lengths given by the elements of prices and selling them.
 *
 * @param len An integer representing the length of the rod to be cut.
 * @param prices A vector of integers representing the prices of the pieces of the rod of length
 *               given by the elements of prices.
 *
 * @return An integer representing the maximum value that can be obtained by cutting the rod of
 *         length len into pieces of lengths given by the elements of prices and selling them.
 */
int rodCutting(int len, vector<int>& prices){
    /**
     * Create a vector dp of size (len+1) to store the maximum value that can be obtained by
     * cutting the rod of length i into pieces of lengths given by the elements of prices and
     * selling them.
     */
    vector<int> dp(len + 1, 0);

    /**
     * Iterate over each possible length of the rod from 1 to len, inclusive.
     */
    for(int i=1;i<=len;++i){
        /**
         * Iterate over each possible price of the pieces of the rod from 0 to i, inclusive.
         */
        for(int j=0;j<=i;++j){
            /**
             * Calculate the maximum value that can be obtained by cutting the rod of length i
             * into a piece of length j and selling it, and then cutting the remaining piece of
             * length i-j-1 into pieces of lengths given by the elements of prices and selling
             * them.
             *
             * If the current price is greater than the maximum value that can be obtained by
             * cutting the rod of length i into pieces of lengths given by the elements of prices
             * and selling them, then update the maximum value that can be obtained by cutting the
             * rod of length i into pieces of lengths given by the elements of prices and selling
             * them.
             */
            dp[i] = max(dp[i], prices[j] + dp[i - j - 1]);
        }
    }

    /**
     * Return the maximum value that can be obtained by cutting the rod of length len into pieces
     * of lengths given by the elements of prices and selling them.
     */
    return dp[len];
}

int main() {
    int length = 4;
    vector<int> price = {2, 5, 7, 8};
    cout << "Maximum profit: " << rodCutting(length, price) << endl;
    return 0;
}