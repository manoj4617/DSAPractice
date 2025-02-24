/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    /**
     * This function is a recursive depth-first search function that counts the number
     * of distinct subsequences in a given string s that are equal to the given string
     * t.
     *
     * The function takes the following parameters:
     *  - i: The current index in the string s.
     *  - j: The current index in the string t.
     *  - s: The given string s.
     *  - t: The given string t.
     *  - memo: A memoization table to store the results of subproblems.
     *
     * The function returns the number of distinct subsequences in s that are equal to t.
     */
    int dfs(int i, int j, string& s, string t, vector<vector<int>>& memo){
        /**
         * If the current index j in the string t is equal to the length of the string
         * t, then we have successfully found a subsequence in s that is equal to t.
         * In this case, we return 1 to indicate that we have found a subsequence.
         */
        if(j == t.length()) return 1;

        /**
         * If the current index i in the string s is equal to the length of the string
         * s, then we have reached the end of the string s and there are no more
         * subsequences in s that can be equal to t. In this case, we return 0 to
         * indicate that we have not found a subsequence.
         */
        if(i == s.length()) return 0;

        /**
         * If the memoization table memo has a result for the current subproblem (i, j),
         * then we can simply return the result from the table instead of recomputing
         * it. This is the memoization step.
         */
        if(memo[i][j] != -1) return memo[i][j];

        /**
         * We recursively call the dfs function on the next index i + 1 in the string
         * s and the current index j in the string t. This is the recursive step.
         */
        int res = dfs(i + 1, j, s, t, memo);

        /**
         * If the current character s[i] in the string s is equal to the current
         * character t[j] in the string t, then we can recursively call the dfs
         * function on the next index i + 1 in the string s and the next index j + 1
         * in the string t. This is the recursive step.
         */
        if(s[i] == t[j]){
            res += dfs(i + 1, j + 1, s, t, memo);
        }

        /**
         * We store the result of the current subproblem in the memoization table memo.
         * This is the memoization step.
         */
        return memo[i][j] = res;
    }

    int numDistinct(string s, string t) {
        if(t.length() > s.length()) return 0;
        vector<vector<int>> memo(s.size() , vector<int>(t.size() + 1, -1));
        return dfs(0,0,s,t,memo);
    }
};

int main(){
    string s = "rabbbit";
    string t = "rabbit";

    Solution obj;
    cout << obj.numDistinct(s,t) << endl;
    return 0;
}
// @lc code=end

