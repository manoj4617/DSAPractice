#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

/**
 * This is a recursive function that uses memoization to check if the
 * string s1 and s2 can be interleaved to form the string s3.
 *
 * The function takes the following parameters:
 *  - i: The current index in the string s1.
 *  - j: The current index in the string s2.
 *  - k: The current index in the string s3.
 *  - s1: The first string.
 *  - s2: The second string.
 *  - s3: The interleaved string.
 *
 * The function first checks if the current index k has reached the end of
 * the string s3. If it has, then the function returns true if the current
 * index i has reached the end of the string s1 and the current index j has
 * reached the end of the string s2. Otherwise, the function returns false.
 *
 * The function then checks if the current subproblem has already been solved
 * by looking up the result in the memoization table dp. If the result is
 * already in the table, the function returns the result directly.
 *
 * If the subproblem has not been solved yet, the function checks if the
 * current character in the string s1 matches the current character in the
 * string s3. If it does, the function recursively calls itself with the
 * next index in the string s1. Otherwise, the function recursively calls
 * itself with the next index in the string s2.
 *
 * The function then stores the result in the memoization table dp and returns
 * it.
 */
bool backtrack(int i, int j, int k, string& s1, string& s2, string& s3){
    // Check if the current index k has reached the end of the string s3.
    if(k == s3.length()){
        // Return true if the current index i has reached the end of the string s1
        // and the current index j has reached the end of the string s2.
        return (i == s1.length() && j == s2.length());
    }

    // Check if the current subproblem has already been solved by looking up
    // the result in the memoization table dp.
    if(dp[i][j] != -1){
        // Return the result directly if it is already in the table.
        return dp[i][j];
    }

    // Initialize a variable res to false.
    bool res = false;

    // Check if the current character in the string s1 matches the current
    // character in the string s3.
    if(i < s1.length() && s1[i] == s3[k]){
        // If it does, recursively call the function with the next index in the
        // string s1.
        res = backtrack(i + 1, j, k + 1, s1,s2,s3);
    }

    // If the current character in the string s1 does not match the current
    // character in the string s3, or if the current index i has reached the
    // end of the string s1, then check if the current character in the string
    // s2 matches the current character in the string s3.
    if(!res && j < s2.length() && s2[j] == s3[k]){
        // If it does, recursively call the function with the next index in the
        // string s2.
        res = backtrack(i, j + 1, k + 1, s1,s2,s3);
    }

    // Store the result in the memoization table dp.
    dp[i][j] = res;

    // Return the result.
    return res;
}

bool interleave(string& s1, string& s2, string& s3){
    int l1 = s1.length();
    int l2 = s2.length();
    if(l1 + l2 != s3.length()){
        return false;
    }
    dp = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
    return backtrack(0,0,0,s1,s2,s3);
}

int main(){
    string s1,s2,s3;
    cin >> s2 >> s2 >> s3;

    cout << "Can interleave: " << s1 << " and: " << s2 << " to form: " << s3 << " " <<interleave(s1,s2,s3) << endl;

}