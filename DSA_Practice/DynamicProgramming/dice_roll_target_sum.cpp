#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

    /**
     * This function is a recursive helper function for numRollsToTarget.
     * It takes in the following parameters:
     *   i: the current index we are at in the sequence of dice rolls
     *   n: the total number of dice rolls
     *   k: the number of sides on the dice
     *   curSum: the current sum of the dice rolls
     *   target: the target sum we are trying to reach
     *   memo: a memoization table to store the results of subproblems
     *
     * The function returns the number of ways to reach the target sum by
     * rolling the dice n times, where each die has k sides.
     *
     * The base case is when we have reached the last die (i.e. i == n). In
     * this case, we simply return whether the current sum is equal to the
     * target sum or not.
     *
     * If we have already computed the result of the current subproblem, we
     * simply return the result from the memoization table.
     *
     * Otherwise, we iterate over each possible value of the current die
     * (from 1 to k) and recursively call the function with the updated
     * current sum. We then add up the results of the recursive calls and
     * return the result modulo MOD (to prevent overflow).
     *
     * Finally, we store the result in the memoization table so that we
     * don't have to compute it again.
     */
    int dfs(int i, int n, int k, int curSum, int target, vector<vector<int>>& memo){
        if(i == n){
            // Base case: if we have reached the last die, simply return
            // whether the current sum is equal to the target sum or not.
            return curSum == target;
        }

        if(memo[i][curSum] != -1){
            // If we have already computed the result of the current
            // subproblem, simply return the result from the memoization
            // table.
            return memo[i][curSum];
        }

        int count = 0;
        for(int j=1;j<=k;++j){
            // Iterate over each possible value of the current die (from 1
            // to k) and recursively call the function with the updated
            // current sum.
            if(curSum + j <= target){
                count = (count + dfs(i+1,n,k,curSum + j,target,memo)) % MOD;
            }
        }

        // Store the result in the memoization table so that we don't have
        // to compute it again.
        return memo[i][curSum] = count;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return dfs(0,n,k,0, target,memo);
    }

int main(){
    int n = 2;
    int k = 6;
    int target = 7;
    cout << numRollsToTarget(n,k,target);
    return 0;
}