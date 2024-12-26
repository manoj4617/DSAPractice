#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, bool> memo;
/**
 * This is a helper function that performs a depth-first search on the memo
 * table to see if the string can be broken down into a sequence of words
 * contained in the dictionary. The function takes an index i into the string,
 * the string itself, and the dictionary of words as arguments.
 *
 * @param i The current index into the string.
 * @param str The string to be broken down into a sequence of words.
 * @param dict The dictionary of words.
 * @return True if the string can be broken down into a sequence of words
 *         contained in the dictionary, false otherwise.
 */
bool dfs(int i, string& str, vector<string>& dict){
    /**
     * If the memo table already contains the result for the current index, we
     * can just return that result instead of recomputing it.
     */
    if(memo.find(i) != memo.end()){
        return memo[i];
    }

    /**
     * Iterate over the dictionary of words, and for each word, check if the
     * substring of the string from the current index to the length of the word
     * is equal to the word. If it is, then we have found a valid word that can
     * be used to form a sequence of words from the string.
     */
    for(string& w : dict){
        if(i + w.length() <= str.length() && str.substr(i, i + w.length()) == w){
            /**
             * If we have found a valid word, then we can recursively call
             * dfs on the substring of the string from the current index to the
             * length of the word, and see if we can form a sequence of words
             * from the rest of the string. If we can, then we can return true.
             */
            if(dfs(i + w.length(), str, dict)){
                memo[i] = true;
                return true;
            }
        }
    }

    /**
     * If we have iterated over all the words in the dictionary and have not
     * found any valid words that can be used to form a sequence of words from
     * the string, then we return false.
     */
    return memo[i];
}

bool wordBreak(string& str, vector<string>& dict){
    memo[str.length()] = true;
    return dfs(0, str, dict);
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