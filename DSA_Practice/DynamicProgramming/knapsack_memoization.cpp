#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> t(102, vector<int>(1002,-1));

/**
 * @brief This function implements the 0/1 Knapsack problem using a
 * memoization approach.
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
int KnapsackMemo(vector<int>& wt, vector<int>& val, int maxWt, int n){
    // Base condition: if the maximum weight of the knapsack is 0, or if there
    // are no more items to consider, then the maximum value that can be
    // obtained is 0.
    if(maxWt == 0 || n == 0){
        return 0;
    }

    // If the maximum value for the current subproblem has already been
    // computed, then return it.
    if(t[n][maxWt] != -1){
        return t[n][maxWt];
    }

    // If the weight of the current item is less than or equal to the maximum
    // weight of the knapsack, then we have two options: either include the
    // current item in the subset, or not include the current item in the
    // subset.
    if(wt[n-1] <= maxWt){
        // Calculate the maximum value that can be obtained by including the
        // current item in the subset.
        int inc = val[n-1] + KnapsackMemo(wt, val, maxWt - val[n-1], n - 1);

        // Calculate the maximum value that can be obtained by not including
        // the current item in the subset.
        int exc = KnapsackMemo(wt, val, maxWt, n - 1);

        // Store the maximum value that can be obtained by considering the
        // current item in the subset in the table.
        t[n][maxWt] = max(inc, exc);

        // Return the maximum value that can be obtained by considering the
        // current item in the subset.
        return t[n][maxWt];
    }
    // If the weight of the current item is greater than the maximum weight of
    // the knapsack, then we cannot include the current item in the subset, so
    // we return the maximum value that can be obtained by considering the
    // remaining items and the remaining weight of the knapsack.
    else if(wt[n - 1] > maxWt){
        // Store the maximum value that can be obtained by considering the
        // remaining items and the remaining weight of the knapsack in the
        // table.
        t[n][maxWt] = KnapsackMemo(wt, val, maxWt, n - 1);

        // Return the maximum value that can be obtained by considering the
        // remaining items and the remaining weight of the knapsack.
        return t[n][maxWt];
    }
}

int main(){
    int n, maxWt = 4;
    // cin >> n >> maxWt;
    
    vector<int> wt = {4, 5, 1};
    vector<int> val = { 1, 2, 3 };

    // for(int i=0;i<n;++i){
    //     int t_w, t_v;
    //     cin >> t_w >> t_v;
    //     wt.push_back(t_w);
    //     val.push_back(t_v);
    // }
    cout << "Max profit: " << KnapsackMemo(wt, val,maxWt, wt.size());
    return 0;
}