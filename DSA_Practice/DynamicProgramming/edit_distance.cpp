#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * This function takes two strings as input and returns the minimum number of
 * operations (insertions, deletions, substitutions) required to transform the
 * first string into the second string.
 */
int minDistance(string word1, string word2){
    // edge case: if word1 is empty, then the minimum number of operations is
    // simply the length of word2
    if(word1.length() == 0){
        return word2.length();
    }
    // edge case: if word2 is empty, then the minimum number of operations is
    // simply the length of word1
    if(word2.length() == 0){
        return word1.length();
    }

    int m = word1.length(), n = word2.length();
    // create a 2D array dp of size (m+1) x (n+1) to store the minimum number of
    // operations required to transform the first i characters of word1 into the
    // first j characters of word2
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    // initialize the first row and first column of dp to represent the edge
    // cases
    for(int i=0;i<=m;++i){
        dp[i][0] = i;
    }
    for(int j=0;j<=n;++j){
        dp[0][j] = j;
    }

    // iterate over the 2D array dp and fill in the values
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            // if the current characters of word1 and word2 are equal, then the
            // number of operations is simply the number of operations required
            // to transform the first i-1 characters of word1 into the first j-1
            // characters of word2
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                // otherwise, the number of operations is 1 plus the minimum of
                // the number of operations required to transform the first i-1
                // characters of word1 into the first j characters of word2, the
                // number of operations required to transform the first i
                // characters of word1 into the first j-1 characters of word2, and
                // the number of operations required to transform the first i-1
                // characters of word1 into the first j-1 characters of word2
                dp[i][j] = 1 + min({
                    dp[i-1][j],  // Delete - We're removing a character from string1, so we move one position back in string1 (i-1) but stay at the same position in string2
                    dp[i][j-1],  //Insert - We're inserting a character into string1 to match string2, so we move one position back in string2 (j-1) but stay at the same position in string1
                    dp[i-1][j-1] //  Replace - We're replacing a character in string1 with a character from string2, so we move back one position in both strings
                });
            }
        }
    }
    // return the value at the bottom right of the dp array, which is the
    // minimum number of operations required to transform the entire word1 into
    // the entire word2
    return dp[m][n];
}

int main(){
    string word1 = "monkeys";
    string word2 = "money";

    cout << "Min distance from: " << word1 << " to " << word2 << " " << minDistance(word1, word2);
    return 0;
}