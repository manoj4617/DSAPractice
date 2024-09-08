#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function implements the 0/1 Knapsack problem using a
 * top-down (or memoization) approach.
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
    // Create a matrix t of size (n+1)x(maxWt+1) to store the maximum value
    // that can be obtained by considering the first i items and the maximum
    // weight of the knapsack j.
    vector<vector<int>> t(n + 1, vector<int>(maxWt + 1));

    // Initialize the first row and first column of t to 0, since there are
    // no items to consider, or the maximum weight of the knapsack is 0.
    for(int i=0;i<n+1;++i){
        for(int j=0;j<maxWt+1;++j){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    // Iterate over each row and column of t, starting from the second row
    // and second column (since the first row and first column are already
    // initialized to 0).
    for(int i=1;i<n + 1;++i){
        for(int w = 1; w < maxWt + 1; ++w){
            // If the current item is not included in the subset, then the
            // maximum value that can be obtained is the same as the maximum
            // value that can be obtained without including the current item.
            if(wt[i - 1] > w){
                t[i][w] = t[i - 1][w];
            }
            // If the current item is included in the subset, then the maximum
            // value that can be obtained is the maximum of two options: either
            // include the current item in the subset and add its value to the
            // maximum value that can be obtained by considering the remaining
            // items and the remaining weight of the knapsack, or do not include
            // the current item in the subset and consider the remaining items
            // and the remaining weight of the knapsack.
            else {
                t[i][w] = max(
                    val[i - 1] + t[i - 1][w - wt[i - 1]],
                    t[i - 1][w]
                );
            }
        }
    }

    // Return the maximum value that can be obtained by considering all the
    // items and the maximum weight of the knapsack.
    return t[n][maxWt];
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