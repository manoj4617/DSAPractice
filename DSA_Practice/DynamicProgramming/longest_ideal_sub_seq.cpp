#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Computes the length of the longest ideal subsequence in the given string.
 * 
 * The longest ideal subsequence is a subsequence of characters in the string
 * such that the difference between any two adjacent characters in the subsequence
 * is at most k. This function uses dynamic programming to solve the problem in
 * O(n) time, where n is the length of the input string.
 * 
 * @param s The input string.
 * @param k The maximum difference between adjacent characters in the subsequence.
 * @return int The length of the longest ideal subsequence.
 */
int longestIdealSubSeq(string s, int k){
    int n = s.length();
    // dp[i] stores the length of the longest ideal subsequence ending with the
    // character with index i in the alphabet.
    vector<int> dp(26,0);

    // Iterate over the characters in the string.
    for(char c : s){
        // Convert the character to its index in the alphabet.
        int cur = c - 'a';
        // Initialize the length of the longest subsequence ending at this
        // character to 1.
        int longest = 1;
        // Iterate over the previous characters in the alphabet.
        for(int prev = 0; prev < 26;++prev){
            // If the difference between the current character and the previous
            // character is at most k, update the length of the longest
            // subsequence ending at the current character.
            if(abs(cur - prev) <= k){
                longest = max(longest, 1 + dp[prev]);
            }
        }
        // Update the dp array with the length of the longest subsequence ending
        // at this character.
        dp[cur] = max(longest, dp[cur]);
    }
    // Return the maximum length of any ideal subsequence.
    return *max_element(dp.begin(), dp.end());
}


int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << "Longest ideal sub seq: " << longestIdealSubSeq(s, k);
    return 0;
}