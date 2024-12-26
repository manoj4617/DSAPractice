#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostToPaintHouses2(vector<vector<int>>& houses) {
    int len = houses.size();  // Number of houses
    int k = houses[0].size(); // Number of colors available for painting

    // Create a 2D dp vector to store the minimum cost for each house and color combination
    vector<vector<int>> dp(len, vector<int>(k));

    // Initialize the dp table for the first house with its respective painting costs
    for (int i = 0; i < k; ++i) {
        dp[0][i] = houses[0][i];
    }

    // Iterate over each house starting from the second one
    for (int i = 1; i < len; ++i) {
        // For each color option for the current house
        for (int j = 0; j < k; ++j) {
            int minCost = INT_MAX;  // Initialize the minimum cost for the current house with the current color

            // Find the minimum cost of painting the previous house with a different color
            for (int l = 0; l < k; ++l) {
                if (l == j) continue;  // Skip the current color to ensure no two adjacent houses have the same color
                minCost = min(minCost, dp[i - 1][l]);  // Update the minimum cost
            }

            // Update the dp table with the minimum cost of painting the current house with the current color
            dp[i][j] = minCost + houses[i][j];
        }
    }
    
    // Return the minimum cost of painting all houses from the last row of the dp table
    return *min_element(dp[len - 1].begin(), dp[len - 1].end());
}

/**
 * This function is an optimized version of the minCostToPaintHouses2 function. It
 * does the same thing as minCostToPaintHouses2, but it is more memory efficient as
 * it only uses a single vector of size k to keep track of the dp table, as opposed
 * to the previous version which used a 2D vector with n rows and k columns.
 *
 * @param houses A 2D vector where houses[i][j] represents the cost of painting the
 *               i-th house with the j-th color. It is assumed that houses[i] contains
 *               exactly k elements, corresponding to the costs of painting the
 *               house with k different colors.
 *
 * @return The minimum cost to paint all houses such that no two adjacent houses
 *         have the same color.
 *
 * The algorithm works as follows:
 * 1. Initialize a dp table with k elements, where dp[i] represents the minimum cost
 *    to paint up to the i-th house with the j-th color.
 * 2. For each house, calculate the minimum cost to paint it with each color by
 *    adding the cost of painting the current house with the current color to the
 *    minimum cost of painting the previous house with a different color. This
 *    ensures that no two adjacent houses have the same color.
 * 3. Finally, return the minimum value from the dp table, which represents the
 *    minimum cost to paint all houses.
 */
int minCostToPaintHouses2Optimized(vector<vector<int>>& houses){
    int len = houses.size();
    int k = houses[0].size();
    vector<int> dp(k);

    // Initialize the dp table to be the same as the first row of the houses vector.
    for(int i=0;i<k;++i){
        dp[i] = houses[0][i];
    }

    // Iterate through each house and calculate the minimum cost to paint it with each color.
    for(int i=1;i<len;++i){
        // min1 is the minimum cost to paint the current house with the first color.
        int min1 = INT_MAX;
        // min2 is the minimum cost to paint the current house with the second color.
        int min2 = INT_MAX;
        // minIdx is the index of the color that has the minimum cost to paint the current house.
        int minIdx = -1;
        for(int j=0;j<k;++j){
            if(dp[j] < min1){
                // If the cost of painting the current house with the current color is less than min1,
                // then update min2 to be min1 and update min1 to be the current cost.
                min2 = min1;
                min1 = dp[j];
                // Update minIdx to be the current index.
                minIdx = j;
            }
            else if(dp[j] < min2){
                // If the cost of painting the current house with the current color is less than min2,
                // then update min2 to be the current cost.
                min2 = dp[j];
            }
        }

        // Create a temporary vector to store the dp table for the current house.
        vector<int> temp(k);
        // Iterate through each color and calculate the minimum cost to paint the current house with it.
        for(int j=0;j<k;++j){
            // If the current color is the same as the color that has the minimum cost to paint the current house,
            // then set the dp table for the current color to be min2, otherwise set it to min1.
            temp[j] = (j == minIdx ? min2 : min1) + houses[i][j];
        }
        // Update the dp table to be the temporary vector.
        dp = temp;
    }
    // Return the minimum value from the dp table, which represents the minimum cost to paint all houses.
    return *min_element(dp.begin(), dp.end());
}

int main()
{
    int n, k;
    cin >> n >>k;
    vector<vector<int>> houses(n,vector<int>(3));
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            cin >> houses[i][j];
        }
    }
    cout << minCostToPaintHouses2(houses) << endl;
    return 0;
}