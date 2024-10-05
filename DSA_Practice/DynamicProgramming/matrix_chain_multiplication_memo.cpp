#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers, arr, and two indices i and j as
 * input, and returns the minimum number of scalar multiplications required
 * to multiply the matrices from index i to j in the given vector.
 *
 * The function uses a memoization approach to store the results of subproblems
 * and reuse them to avoid redundant computation.
 *
 * The function first checks if the subproblem has already been solved by
 * checking if the element at memo[i][j] is not -1. If it is not -1, the
 * function returns the value at memo[i][j] directly.
 *
 * If the subproblem has not been solved yet, the function iterates over each
 * possible split point from i to j-1. For each split point, the function
 * recursively calls itself to compute the minimum number of scalar
 * multiplications required to multiply the matrices from i to the split point
 * and from the split point+1 to j. The function then adds the cost of
 * multiplying the two resulting matrices (which is the product of the
 * dimensions of the matrices at indices i-1, k, and j) and assigns the minimum
 * of this sum and the current answer to the answer.
 *
 * Finally, the function stores the answer in memo[i][j] and returns it.
 */
int MCM_Memoization(vector<int>& arr, vector<vector<int>>& memo, int i , int j){
    // Base case: if i >= j, then there is only one matrix, so
    // the number of scalar multiplications required is 0
    if(i >= j){
        return 0;
    }

    // If the subproblem has already been solved, return the result directly
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    // Initialize the answer to the maximum possible value
    int ans = INT_MAX;

    // Iterate over each possible split point from i to j-1
    for(int k=i;k<=j-1;++k){
        // Recursively call the function to compute the minimum number of
        // scalar multiplications required to multiply the matrices from i to
        // the split point and from the split point+1 to j
        int temp = MCM_Memoization(arr, memo, i, k) + MCM_Memoization(arr, memo, k + 1, j);

        // Add the cost of multiplying the two resulting matrices
        temp += arr[i-1] * arr[k] * arr[j];

        // Update the answer to the minimum of this sum and the current answer
        ans = min(temp, ans);
    }

    // Store the answer in memo[i][j] and return it
    memo[i][j] = ans;
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> memo(n, vector<int>(n,-1));
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    cout << MCM_Memoization(arr, memo, 1, n-1);
    return 0;
}