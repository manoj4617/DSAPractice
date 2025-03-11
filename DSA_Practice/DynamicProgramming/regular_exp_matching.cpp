#include <iostream>
#include <vector>

using namespace std;

/**
 * This is a recursive function that uses memoization to check if a given
 * string s matches a given regular expression p.
 *
 * The function takes the following parameters:
 *  - i: The current index in the string s.
 *  - j: The current index in the regular expression p.
 *  - m: The length of the string s.
 *  - n: The length of the regular expression p.
 *  - s: The string to be matched.
 *  - p: The regular expression.
 *  - memo: A memoization table to store the results of subproblems.
 *
 * The function first checks if the memoization table already contains the
 * result for the current subproblem. If it does, the function returns the
 * result directly. This is the memoization step.
 *
 * If the subproblem has not been solved yet, the function checks if the
 * regular expression p has been exhausted. If it has, and the string s has also
 * been exhausted, then the function returns true. Otherwise, the function
 * returns false.
 *
 * If the regular expression p has not been exhausted, the function checks if
 * the current character in the string s matches the current character in the
 * regular expression p. If it does, or if the current character in the regular
 * expression p is a '.', then the function sets a flag match to true.
 *
 * The function then checks if the next character in the regular expression p
 * is a '*'. If it is, the function recursively calls itself twice. The first
 * call is to check if the '*' can be ignored, and the second call is to check
 * if the '*' can be used to match the current character in the string s.
 *
 * If the next character in the regular expression p is not a '*', the function
 * recursively calls itself once to check if the current character in the
 * string s matches the current character in the regular expression p.
 *
 * Finally, the function stores the result in the memoization table and returns
 * it.
 */
bool backtrack(int i, int j, int m, int n, string& s, string& p, vector<vector<bool>>& memo){
    // Check if the memoization table already contains the result for the
    // current subproblem. If it does, return the result directly.
    if(memo[i][j]){
        return memo[i][j];
    }

    // If the regular expression p has been exhausted, and the string s has also
    // been exhausted, then return true.
    if(j >= n && i >= m){
        return true;
    }

    // If the regular expression p has been exhausted, but the string s has not
    // been exhausted, then return false.
    if(j >= n){
        return false;
    }

    // Check if the current character in the string s matches the current
    // character in the regular expression p. If it does, or if the current
    // character in the regular expression p is a '.', then set a flag match to
    // true.
    bool match = (i < m) && (s[i] == p[j] || p[j] == '.');

    // If the next character in the regular expression p is a '*', then
    // recursively call the function twice. The first call is to check if the
    // '*' can be ignored, and the second call is to check if the '*' can be
    // used to match the current character in the string s.
    if(j + 1 < n && p[j + 1] == '*'){
        memo[i][j] = (backtrack(i, j + 2, m, n, s, p, memo) ||          // not use the * 
                      match && backtrack(i + 1, j, m, n, s, p, memo));  // use the *
    }
    else{
        // If the next character in the regular expression p is not a '*',
        // then recursively call the function once to check if the current
        // character in the string s matches the current character in the
        // regular expression p.
        memo[i][j] = match && backtrack(i + 1, j + 1, m, n, s, p, memo);
    }
    return memo[i][j];
}

bool isMatching(string& s, string& p){
    int m = s.length(), n = p.length();
    vector<vector<bool>> memo(m + 1, vector<bool>(n + 1, false));
    return backtrack(0, 0, m, n, s, p, memo);
}

int main(){
    string s, p;
    cin >> s >> p;
    cout << "Regular expression match\n";
    cout << "s: " << s << " " << " p: " << p << " -> " << 
        (isMatching(s, p) ? "Match" : "Do not match") << endl;
    return 0;
}