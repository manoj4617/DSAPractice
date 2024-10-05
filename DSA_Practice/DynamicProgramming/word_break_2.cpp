#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * This function takes a vector of strings and a string as input and returns a
 * vector of strings as output. The output vector contains all the possible
 * combinations of words that can be formed from the input string by using the
 * words in the dictionary.
 *
 * The function first creates a 2D vector dp of size n+1, where dp[i] is a vector
 * of strings representing all the possible combinations of words that can be
 * formed from the input string of length i. The first element of dp is an empty
 * string, representing the empty combination of words.
 *
 * The function then iterates over the input string from left to right, and for
 * each prefix of the string, it checks if the suffix of the prefix is in the
 * dictionary. If it is, then it adds all the possible combinations of words that
 * can be formed from the prefix to the current dp[i].
 *
 * Finally, the function returns the dp[n], which is all the possible
 * combinations of words that can be formed from the input string of length n.
 */
vector<string> wordBreak2(const vector<string>& dict, const string& str){
    int n = str.length();
    vector<vector<string>> dp(n + 1, vector<string>());
    dp[0] = {""}; // dp[i] will contain all the possible combinations of words
                   // that can be formed from the input string of length i

    for(int i=1;i<=n;++i){
        string prefix = str.substr(0,i); // prefix is the first i characters of
                                          // the input string
        vector<string> temp;

        for(int j=0;j<i;++j){
            string suffix = prefix.substr(j); // suffix is the substring of
                                               // prefix from index j to the end
            if(find(dict.begin(), dict.end(), suffix) != dict.end()){
                // if suffix is in the dictionary, then it's a valid combination
                // of words
                for(const string& subStr : dp[j]){
                    // dp[j] will contain all the possible combinations of words
                    // that can be formed from the prefix of length j
                    temp.push_back(subStr + (subStr.empty() ? "" :" ") + suffix);
                }
            }
        }
        dp[i] = temp; // dp[i] will contain all the possible combinations of
                       // words that can be formed from the prefix of length i
    }
    return dp[n]; // return all the possible combinations of words that can be
                   // formed from the input string of length n
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

    vector<string> res = wordBreak2(dict, str);
    for(const string& r : res){
        cout << r << " ";
    }
    return 0;

}