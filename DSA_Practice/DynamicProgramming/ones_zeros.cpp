#include <iostream>
#include <vector>

using namespace std;

pair<int,int> countZerosOnes(const string str){
    pair<int,int> count;
    int ones = 0;
    int zeros = 0;
    for(const char& c : str){
        if(c == '0'){
            ++zeros;
        }
        else if(c == '1'){
            ++ones;
        }
    }
    return make_pair(zeros, ones);
}
int findMaxForm(vector<string>& strs, int m, int n) {
    // Get the number of strings in the input vector
    int len = strs.size();
    // Create a 2D DP array with dimensions (m+1) x (n+1) initialized to 0
    // dp[i][j] will store the maximum number of strings that can be formed with i zeros and j ones
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Iterate through each string in the input vector
    for(const string& str : strs){
        // Count the number of zeros and ones in the current string
        pair<int,int> p = countZerosOnes(str);
        int zeros = p.first;
        int ones = p.second;
        
        // Update the DP table from bottom to top and right to left
        // This ensures that we do not overwrite the results we are using in calculations
        for(int i = m; i >= zeros; --i){
            for(int j = n; j >= ones; --j){
                // Calculate the maximum number of strings that can be formed
                // by including the current string or excluding it
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }
    
    // Return the maximum number of strings that can be formed with m zeros and n ones
    return dp[m][n];
}


vector<vector<vector<int>>> dp;
/**
 * This is a depth-first search (DFS) function that is used to
 * find the maximum number of strings that can be formed with m zeros
 * and n ones from the given vector of strings.
 *
 * The function takes the following parameters:
 * - i: the current index of the string in the vector
 * - strs: the vector of strings
 * - m: the number of zeros
 * - n: the number of ones
 * - arr: a 2D vector where arr[i][0] is the number of zeros in the string
 *        strs[i] and arr[i][1] is the number of ones in the string strs[i]
 *
 * The function returns the maximum number of strings that can be formed
 * with m zeros and n ones from the given vector of strings.
 */
int dfs(int i, vector<string>& strs, int m, int n, vector<vector<int>>& arr){
    // Base case 1: if we have reached the end of the vector of strings
    if(i == strs.size()){
        return 0;
    }

    // Base case 2: if we have used up all the zeros and ones
    if(m == 0 || n == 0){
        return 0;
    }

    // If we have already computed the result for the current string index, m and n,
    // then return the result directly
    if(dp[i][m][n] != -1){
        return dp[i][m][n];
    }

    // Recursive case: try to include the current string in the maximum
    // number of strings that can be formed
    int res = dfs(i + 1, strs, m,n,arr);
    if(m >= arr[i][0] && n >= arr[i][1]){
        // If the current string can be included in the maximum number of strings
        // that can be formed, then try to include it and see if it leads to a
        // larger maximum
        res = max(res, 1 + dfs(i + 1, strs , m - arr[i][0], n - arr[i][1], arr));
    }
    // Store the result in the DP table so that we can avoid recomputing it
    dp[i][m][n] = res;
    return res;
}

int findMaxFromDFS(vector<string>& strs, int m, int n){
    vector<vector<int>> arr(strs.size(), vector<int>(2));
    for(int i=0;i<strs.size();++i){
        for(char& c : strs[i]){
            arr[i][c - '0']++;
        }
    }
    dp.resize(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
    return dfs(0,strs, m, n, arr);
}

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    // cout << findMaxForm(strs, m, n) << endl;
    cout << findMaxFromDFS(strs, m, n) << endl;

    return 0;
}