#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function implements the unbounded knapsack problem using a
 * 2D dynamic programming approach. The approach is to create a 2D matrix dp of
 * size (n+1) x (maxWt+1), where dp[i][j] is the maximum value that can be
 * obtained by considering the first i items and the maximum weight j.
 *
 * The outer loop iterates over each item, starting from the first item.
 * The inner loop iterates over each possible weight from 1 to maxWt, starting
 * from the smallest weight.
 *
 * For each pair of item and weight, the function checks if the weight of the
 * current item is less than or equal to the current weight j. If it is, the
 * function calculates the maximum value that can be obtained by including the
 * current item in the subset, or not including the current item in the subset.
 * The maximum value is the maximum of the two options.
 *
 * If the weight of the current item is greater than the current weight j, the
 * function sets dp[i][j] to be dp[i-1][j], which is the maximum value that can
 * be obtained by considering the first i-1 items and the maximum weight j.
 *
 * Finally, the function returns dp[n][maxWt], which is the maximum value that
 * can be obtained by considering all the items and the maximum weight of the
 * knapsack.
 */
int UnboundedKnapsack_2D(vector<int>& wt, vector<int>& val, int maxWt, int n){
    // Create a 2D matrix dp of size (n+1) x (maxWt+1)
    vector<vector<int>> dp(n + 1, vector<int>(maxWt + 1,0));

    // Iterate over each item, starting from the first item
    for(int i=1;i<=n;++i){
        // Iterate over each possible weight from 1 to maxWt, starting from
        // the smallest weight
        for(int j=1;j<=maxWt;++j){
            // If the weight of the current item is less than or equal to the
            // current weight j, then we have two options: either include the
            // current item in the subset, or not include the current item in
            // the subset.
            if(wt[i - 1] <= j){
                // Calculate the maximum value that can be obtained by
                // including the current item in the subset
                int include = val[i-1] + dp[i][j - wt[i - 1]];

                // Calculate the maximum value that can be obtained by not
                // including the current item in the subset
                int exclude = dp[i - 1][j];

                // The maximum value is the maximum of the two options
                dp[i][j] = max(include, exclude);
            }
            else{
                // If the weight of the current item is greater than the
                // current weight j, then we cannot include the current item in
                // the subset, so we set dp[i][j] to be dp[i-1][j]
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return the maximum value that can be obtained by considering all the
    // items and the maximum weight of the knapsack
    return dp[n][maxWt];
}

/**
 * @brief This function implements the unbounded knapsack problem using a
 * 1-dimensional dynamic programming approach. The approach is to create a
 * vector dp of size (maxWt+1), where dp[i] is the maximum value that can be
 * obtained by using items of total weight i.
 *
 * The outer loop iterates over each possible weight from 1 to maxWt, starting
 * from the smallest weight.
 *
 * The inner loop iterates over each item, starting from the first item.
 *
 * For each item and each weight, the function checks if the weight of the
 * current item is less than or equal to the current weight i. If it is, the
 * function calculates the maximum value that can be obtained by using the
 * current item. The maximum value is the maximum of the current maximum value
 * and the value of the current item plus the maximum value that can be
 * obtained by using the remaining items and the remaining weight i - wt[j].
 *
 * Finally, the function returns dp[maxWt], which is the maximum value that can
 * be obtained by using all the items and the maximum weight of the knapsack.
 */
int UnboundedKnapsack_1D(vector<int>& wt, vector<int>& val, int maxWt, int n){
    // Create a vector dp of size (maxWt+1), where dp[i] is the maximum value
    // that can be obtained by using items of total weight i.
    vector<int> dp(maxWt + 1, 0);

    // Iterate over each possible weight from 1 to maxWt, starting from the
    // smallest weight.
    for(int i=1;i<=maxWt;++i){
        // Iterate over each item, starting from the first item.
        for(int j=0;j<=n;++j){
            // If the weight of the current item is less than or equal to the
            // current weight i, then we have two options: either include the
            // current item in the subset, or not include the current item in
            // the subset.
            if(wt[j] <= i){
                // Calculate the maximum value that can be obtained by
                // including the current item in the subset.
                dp[i] = max(dp[i], val[j] + dp[i - wt[j]]);
            }
        }
    }

    // Return the maximum value that can be obtained by using all the items and
    // the maximum weight of the knapsack.
    return dp[maxWt];
}

int main(){
    int n, maxWt = 100;
    // cin >> n >> maxWt;
    
    vector<int> val = { 10, 30, 20 };
    vector<int> wt = {5, 10, 15};

    // for(int i=0;i<n;++i){
    //     int t_w, t_v;
    //     cin >> t_w >> t_v;
    //     wt.push_back(t_w);
    //     val.push_back(t_v);
    // }
    cout << "Max profit: " << UnboundedKnapsack_1D(wt, val,maxWt, wt.size());
    return 0;
}