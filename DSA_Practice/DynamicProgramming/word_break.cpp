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
    return 0;
}