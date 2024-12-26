#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * This function takes a string and a vector of strings as input and returns a boolean
 * indicating whether or not the string can be broken down into a sequence of words
 * contained in the dictionary. The function uses a dynamic programming approach to
 * solve the problem.
 *
 * The function first initializes a vector dp of size (n+1), where dp[i] is set to
 * true if the substring str[0..i-1] can be broken down into a sequence of words
 * contained in the dictionary, and false otherwise. dp[0] is set to true since an
 * empty string can be broken down into an empty sequence of words.
 *
 * The function then iterates over each character in the string (from index 1 to n),
 * and for each character, it checks if there is a substring of the string that can
 * be broken down into a sequence of words contained in the dictionary, and if the
 * substring of the string is contained in the dictionary. If the substring can be
 * broken down into a sequence of words, then the current substring can also be
 * broken down into a sequence of words. Therefore, the function sets dp[i] to true.
 *
 * Finally, the function returns dp[n], which is true if the string can be broken down
 * into a sequence of words contained in the dictionary, and false otherwise.
 */
bool wordBreak(const string& str, const vector<string>& dict){
    int n = str.length();
    vector<bool> dp(n+1,false);
    dp[0] = true;
    //unordered_set is better in terms of performance than a normal set
    //since it uses hash table internally due to which the lookup is done is
    //O(1). If a set was used the lookup would cost O(log(m))
    //The running time of both the loops in case of unordered_set in O(n^2)
    //in case of set it would be O(n^2 * log(m))

    unordered_set<string> wordSet(dict.begin(), dict.end());
    // Iterate over each character in the string
    for(int i=1;i<=n;++i){
        // Iterate over each possible substring of the string
        for(int j=0;j<i;++j){
            // Check if the substring of the string can be broken down into a
            // sequence of words contained in the dictionary, and if the
            // substring of the string is contained in the dictionary.
            if(dp[j] && wordSet.count(str.substr(j, i - j))){
                // If the substring can be broken down into a sequence of words,
                // then the current substring can also be broken down into a
                // sequence of words. Therefore, set dp[i] to true.
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

/**
 * This function takes a string s and a vector of strings wordDict as input and
 * returns true if the string s can be broken down into a sequence of words
 * contained in the dictionary wordDict, and false otherwise.
 *
 * The function first creates a boolean vector dp of size s.size() + 1, and
 * initializes all the elements of the vector to false except for the last
 * element, which is set to true.
 *
 * The function then iterates over the string s from right to left, and for each
 * index i of the string, it iterates over each word in the dictionary wordDict.
 * For each word w in the dictionary, it checks if the substring of s from index
 * i to i + w.size() is equal to the word w. If it is, then the function sets
 * dp[i] to dp[i + w.size()], which is true if the substring from index i + w.size()
 * to the end of the string can be broken down into a sequence of words contained
 * in the dictionary, and false otherwise.
 *
 * If dp[i] is true, then the function breaks out of the loop, since the substring
 * from index i to the end of the string can be broken down into a sequence of
 * words contained in the dictionary.
 *
 * Finally, the function returns dp[0], which is true if the entire string s can
 * be broken down into a sequence of words contained in the dictionary, and false
 * otherwise.
 */
bool wordBreak2(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[s.size()] = true;

    // Iterate over the string s from right to left
    for (int i = s.size() - 1; i >= 0; i--) {
        // Iterate over each word in the dictionary wordDict
        for (const auto& w : wordDict) {
            // Check if the substring of s from index i to i + w.size() is equal
            // to the word w
            if ((i + w.size()) <= s.size() && 
                 s.substr(i, w.size()) == w) {
                // If the substring is equal to the word w, then set dp[i] to
                // dp[i + w.size()], which is true if the substring from index
                // i + w.size() to the end of the string can be broken down into
                // a sequence of words contained in the dictionary, and false
                // otherwise.
                dp[i] = dp[i + w.size()];
            }
            // If dp[i] is true, then the substring from index i to the end of
            // the string can be broken down into a sequence of words contained
            // in the dictionary. Therefore, break out of the loop.
            if (dp[i]) {
                break;
            }
        }
    }

    // Return dp[0], which is true if the entire string s can be broken down into
    // a sequence of words contained in the dictionary, and false otherwise.
    return dp[0];
}

int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<string> dict(n);
    for(int i=0;i<n;++i){
        cin >> dict[i];
    }

    cout << wordBreak(str, dict);
    cout << wordBreak2(str, dict);
    return 0;
}