#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

/**
 * This function takes a string s as input and returns the number of ways to decode it.
 * The decoding of a string is defined as the number of ways to split the string into
 * substrings, where each substring is a valid number (i.e., it does not contain any
 * leading zeros except for the number 0 itself). For example, the string "123" can
 * be decoded in 3 ways: "1", "2", "3", "12", "23", or "123".

 * The function uses dynamic programming to solve the problem. The dp array is used
 * to store the number of ways to decode each substring of the original string from
 * index 0 to i. The function iterates over each character in the string and for
 * each character, it checks if the character is a valid number (i.e., it does not
 * contain any leading zeros except for the number 0 itself). If the character is a
 * valid number, then the function updates the dp array at the current index to be
 * one more than the value at the previous index. If the character is not a valid
 * number, then the function sets the dp array at the current index to be 0.

 * Finally, the function returns dp[n], which is the number of ways to decode the
 * entire string.
 */
int Decode(string& s){
    int n = s.length();
    if( n == 0 || s[0] == '0'){
        return 0;
    }

    // Create a 1D array dp of size (n+1) to store the number of ways to decode
    // each substring of the original string from index 0 to i.
    vector<int> dp(n + 1, 0);

    // Initialize dp[0] to 1, since there is one way to decode an empty string.
    dp[0] = 1;

    // Initialize dp[1] to 1 if the first character of the string is a valid
    // number, and 0 otherwise.
    dp[1] = (s[0] != 0) ? 1 : 0;

    // Iterate over each character in the string.
    for(int i=2;i<=n;++i){
        // If the current character is a valid number, then the number of ways to
        // decode the substring from index 0 to i is one more than the number of
        // ways to decode the substring from index 0 to i-1.
        if(s[i-1] >= '1' && s[i-1] <= '9'){
            dp[i] += dp[i-1];
        }

        // If the current character and the previous character form a valid number
        // (i.e., a number between 10 and 26), then the number of ways to decode the
        // substring from index 0 to i is one more than the number of ways to decode
        // the substring from index 0 to i-2.
        int num = atoi(s.substr(i-2,2).c_str());
        if(num >= 10 && num <= 26){
            dp[i] += dp[i-2];
        }
    }

    // Return dp[n], which is the number of ways to decode the entire string.
    return dp[n];
}

int main(){
    string s;
    cin >> s;
    cout << Decode(s);
    return 0;
}