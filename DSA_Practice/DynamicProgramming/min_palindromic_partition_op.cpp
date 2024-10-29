#include <iostream>
#include <vector>

using namespace std;


bool isPlindrome(string& s, int i , int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
// This function calculates the minimum number of cuts required to partition
// a substring s[i..j] into palindromic substrings using memoization.
int MCM(string& s, int i, int j, vector<int>& dp) {
    // Base case: If the substring length is 1 or empty, or it is already a palindrome, no cuts are needed.
    if (i >= j || isPlindrome(s, i, j)) {
        return 0;
    }

    // If the result for this substring has already been computed, return the stored result.
    if (dp[i] != -1) {
        return dp[i];
    }

    // Initialize the answer to a large value, representing the maximum possible cuts.
    int ans = INT_MAX;

    // Try every possible split point from i to j-1 to find the minimum cuts needed.
    for (int k = i; k <= j - 1; k++) {
        // If the left part s[i..k] is a palindrome, calculate the cuts needed for the right part s[k+1..j].
        if (isPlindrome(s, i, k)) {
            // Recursive call to find the minimum cuts for the right part, adding 1 for the current cut.
            int temp = MCM(s, k + 1, j, dp) + 1;
            // Update the answer with the minimum cuts found so far.
            ans = min(ans, temp);
        }
    }

    // Store the computed result in the dp array to avoid recomputation.
    dp[i] = ans;
    // Return the minimum number of cuts needed for the current substring.
    return ans;
}
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1, -1);
    return MCM(s, 0 , n-1, dp);
}

int main(){
    string s;
    cin >> s;
    cout << minCut(s);
    return 0;
}