#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * This function takes a vector of strings and groups them by anagrams.
 * It does this by sorting each string and using the sorted string as a
 * key in an unordered map. The values in the map are vectors of strings
 * which are the anagrams of the sorted string. Finally, the code iterates
 * over the map and adds each vector of strings to a result vector.
 *
 * @param str The vector of strings to group.
 * @return A vector of vectors of strings, where each inner vector contains
 *         the anagrams of the sorted string.
 */
vector<vector<string>> GroupAnagram(vector<string>& str){
    /**
     * This map will store the anagrams of the strings. The key is the
     * sorted version of the string, and the value is a vector of strings
     * which are the anagrams of the sorted string.
     */
    unordered_map<string, vector<string>> mp;

    /**
     * Iterate over each string in the input vector.
     */
    for(const auto& s : str){
        /**
         * Create a copy of the string, sort it, and use it as the key
         * in the map.
         */
        string w(s);
        sort(w.begin(), w.end());
        mp[w].push_back(s);
    }

    /**
     * Create a vector to store the result. This vector will contain
     * the anagrams of the strings.
     */
    vector<vector<string>> res;

    /**
     * Iterate over the map and add each vector of strings to the result
     * vector.
     */
    for(const auto& m : mp){
        res.push_back(m.second);
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    vector<string> str(n);
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        str.push_back(s);
    }
    vector<vector<string>> res = GroupAnagram(str);
    for(const auto& r : res){
        for(const auto& i : r){
            cout << i << " ";
        }
        cout << "\n";
    }
}