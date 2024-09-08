#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function implements the 0/1 Knapsack problem using a
 * top-down (or memoization) approach. The approach is to use two vectors to
 * store the maximum value that can be obtained for each subproblem, and then
 * use those vectors to solve the original problem. This approach is more
 * efficient than using a matrix to store the solutions to all subproblems.
 *
 * @param wt A vector of integers representing the weights of the items.
 * @param val A vector of integers representing the values of the items.
 * @param maxWt An integer representing the maximum weight that the knapsack can
 *              hold.
 * @param n An integer representing the number of items to consider.
 *
 * @return An integer representing the maximum value that can be obtained by
 *         selecting a subset of the items such that the total weight of the
 *         subset does not exceed the maximum weight of the knapsack.
 */
int KnapsackTopDown(vector<int>& wt, vector<int>& val, int maxWt, int n){

    // Create two vectors to store the maximum value that can be obtained for
    // each subproblem. The first vector dp is used to store the maximum value
    // that can be obtained by considering the first i items and the maximum
    // weight j. The second vector temp is used to store the maximum value that
    // can be obtained by considering the first i+1 items and the maximum weight
    // j.
    vector<int> dp(maxWt + 1,0);
    vector<int> temp(maxWt + 1,0);

    // Iterate over each item, starting from the first item.
    for(int i=1;i<=n;++i){

        // Iterate over each possible weight from 1 to maxWt, starting from
        // the smallest weight.
        for(int j=1;j<=maxWt;++j){

            // If the weight of the current item is less than or equal to the
            // current weight j, then we have two options: either include the
            // current item in the subset, or not include the current item in
            // the subset.
            if(wt[i - 1] <= j){

                // If we include the current item in the subset, the maximum
                // value that can be obtained is the value of the current item
                // plus the maximum value that can be obtained by considering
                // the remaining items and the remaining weight j - wt[i-1].
                temp[j] = max(val[i - 1] + dp[j - wt[i - 1]], dp[j]);

            }
            // If the weight of the current item is greater than the current
            // weight j, then we cannot include the current item in the
            // subset, so we set the maximum value that can be obtained to the
            // maximum value that can be obtained by considering the remaining
            // items and the remaining weight j.
            else{

                temp[j] = dp[j];

            }
        }

        // After iterating over all possible weights for the current item, we
        // update dp to be temp, so that we can use the maximum values that can
        // be obtained by considering the first i+1 items to solve the
        // subproblem for the next item.
        dp = temp;
    }

    // Finally, we return the maximum value that can be obtained by considering
    // all n items and the maximum weight maxWt.
    return dp[maxWt];
}

int main(){
    int n, maxWt = 50;
    // cin >> n >> maxWt;
    
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };

    // for(int i=0;i<n;++i){
    //     int t_w, t_v;
    //     cin >> t_w >> t_v;
    //     wt.push_back(t_w);
    //     val.push_back(t_v);
    // }
    cout << "Max profit: " << KnapsackTopDown(wt, val,maxWt, wt.size());
    return 0;
}