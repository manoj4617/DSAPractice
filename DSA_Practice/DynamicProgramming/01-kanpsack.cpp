#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function implements the 0/1 Knapsack problem using a
 * recursive approach.
 *
 * @param wt A vector of integers representing the weights of the items.
 * @param val A vector of integers representing the values of the items.
 * @param maxWt An integer representing the maximum weight that the knapsack can hold.
 * @param n An integer representing the number of items to consider.
 *
 * @return An integer representing the maximum value that can be obtained by
 *         selecting a subset of the items such that the total weight of the
 *         subset does not exceed the maximum weight of the knapsack.
 */
int Knapsack(vector<int>& wt, vector<int>& val, int maxWt, int n){
    // Base condition: if there are no more items to consider, or if the
    // maximum weight of the knapsack is 0, then the maximum value that can be
    // obtained is 0.
    if(n == 0 || maxWt == 0){
        return 0;
    }

    // If the weight of the current item is less than or equal to the maximum
    // weight of the knapsack, then we have two options: either include the
    // current item in the subset, or not include the current item in the
    // subset.
    if(wt[n - 1] <= maxWt){
        // If we include the current item in the subset, the maximum value that
        // can be obtained is the value of the current item plus the maximum
        // value that can be obtained by considering the remaining items and
        // the remaining weight of the knapsack.
        int include = val[n - 1] + Knapsack(wt, val, maxWt - wt[n - 1], n - 1);

        // If we don't include the current item in the subset, the maximum value
        // that can be obtained is the maximum value that can be obtained by
        // considering the remaining items and the remaining weight of the
        // knapsack.
        int exclude = Knapsack(wt, val, maxWt, n - 1);

        // We return the maximum of the two options.
        return max(include, exclude);
    }
    // If the weight of the current item is greater than the maximum weight of
    // the knapsack, then we cannot include the current item in the subset, so
    // we return the maximum value that can be obtained by considering the
    // remaining items and the remaining weight of the knapsack.
    else if(wt[n - 1] > maxWt){
        return Knapsack(wt, val, maxWt, n - 1);
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
    cout << "Max profit: " << Knapsack(wt, val,maxWt, wt.size());
    return 0;
}