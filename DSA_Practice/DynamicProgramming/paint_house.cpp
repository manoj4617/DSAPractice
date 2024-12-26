#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Calculates the minimum cost to paint all houses such that no two adjacent houses have the same color.
 * 
 * The function uses dynamic programming to solve the problem. The idea is to maintain a dp table where dp[i][j] 
 * represents the minimum cost to paint up to the i-th house with the j-th color.
 * 
 * @param houses A 2D vector where houses[i][j] represents the cost of painting the i-th house with the j-th color.
 *               It is assumed that houses[i] contains exactly 3 elements, corresponding to the costs of painting 
 *               the house with three different colors.
 * 
 * @return The minimum cost to paint all houses such that no two adjacent houses have the same color.
 * 
 * The algorithm works as follows:
 * 1. Initialize a dp table with the same dimensions as the input houses vector.
 * 2. Set the first row of the dp table to be the same as the first row of the houses vector, as the cost to paint 
 *    the first house is simply the cost given in the input.
 * 3. For each subsequent house, calculate the minimum cost to paint it with each color by adding the cost of painting 
 *    the current house with the current color to the minimum cost of painting the previous house with a different color.
 *    This ensures that no two adjacent houses have the same color.
 * 4. Finally, return the minimum value from the last row of the dp table, which represents the minimum cost to paint 
 *    all houses.
 */
int minCostToPaintHouses(vector<vector<int>>& houses) {
    int n = houses.size();
    vector<vector<int>> dp(n, vector<int>(3));
    for(int i=0;i<3;++i){
        dp[0][i] = houses[0][i];
    }

    for(int i=1;i<n;++i){
        dp[i][0] = houses[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = houses[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = houses[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

/**
 * @brief This function is an optimized version of the minCostToPaintHouses function. It has the same time and space
 * complexity, but it is more memory efficient as it only uses a single vector of size 3 to keep track of the dp
 * table, as opposed to the previous version which used a 2D vector with n rows and 3 columns.
 * 
 * The function uses dynamic programming to solve the problem. The idea is to maintain a dp table where dp[i] represents
 * the minimum cost to paint up to the i-th house with the j-th color.
 * 
 * @param houses A 2D vector where houses[i][j] represents the cost of painting the i-th house with the j-th color.
 *               It is assumed that houses[i] contains exactly 3 elements, corresponding to the costs of painting the
 *               house with three different colors.
 * 
 * @return The minimum cost to paint all houses such that no two adjacent houses have the same color.
 * 
 * The algorithm works as follows:
 * 1. Initialize a dp table with 3 elements, where dp[i] is the minimum cost to paint up to the i-th house with the
 *    j-th color.
 * 2. For each house, calculate the minimum cost to paint it with each color by adding the cost of painting the current
 *    house with the current color to the minimum cost of painting the previous house with a different color. This ensures
 *    that no two adjacent houses have the same color.
 * 3. Finally, return the minimum value from the dp table, which represents the minimum cost to paint all houses.
 */
int minCostToPaintHousesOptimized(vector<vector<int>>& houses) {
    int n = houses.size();
    vector<int> dp(3);
    for(int i=0;i<3;++i){
        dp[i] = houses[0][i];
    }

    for(int i=1;i<n;++i){
        // Create a temporary vector to store the dp table for the current house.
        vector<int> temp(3);

        // Calculate the minimum cost to paint the current house with the first color.
        temp[0] = houses[i][0] + min(dp[1], dp[2]);

        // Calculate the minimum cost to paint the current house with the second color.
        temp[1] = houses[i][1] + min(dp[0], dp[2]);

        // Calculate the minimum cost to paint the current house with the third color.
        temp[2] = houses[i][2] + min(dp[0], dp[1]);

        // Update the dp table to be the temporary vector.
        dp = temp;
    }

    // Return the minimum value from the dp table, which represents the minimum cost to paint all houses.
    return *min_element(dp.begin(), dp.end());
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> houses(n,vector<int>(3));
    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            cin >> houses[i][j];
        }
    }
    cout << minCostToPaintHousesOptimized(houses) << endl;
    return 0;
}