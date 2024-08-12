#include<iostream>
#include<vector>

using namespace std;

/**
 * Function to check if two given strings are isomorphic.
 * Two strings are isomorphic if they have the same characters
 * but different character positions.
 *
 * @param s First string
 * @param t Second string
 * @return True if the strings are isomorphic, False otherwise
 */
bool isIsomorphic(string s, string t) {
    // Create a vector to store the mapping of characters from s to t
    vector<int> arr(256, -1);

    // Create two vectors to keep track of visited characters in s and t
    vector<bool> visited(256, 0); // Elements correspond to ASCII values
    vector<bool> visited1(256, 0); // Elements correspond to ASCII values

    // Iterate over each character in s and t
    for (int i = 0; i < s.length(); i++) {
        // Check if the character in s has already been visited or 
        // if the corresponding character in t has already been visited
        if (visited[s[i]] == 1 || visited1[t[i]] == 1) {
            // If the characters have different mappings, return False
            if (arr[s[i]] != t[i] - 'a') {
                return false;
            }
        } else {
            // If the characters have not been visited, mark them as visited
            visited[s[i]] = 1;
            visited1[t[i]] = 1;

            // Store the mapping of the character in s to the corresponding
            // character in t
            arr[s[i]] = t[i] - 'a';
        }
    }

    // If all characters are isomorphic, return True
    return true;
}
 
int main(){

    string s ,t;
    cin >> s >> t;
    cout << (bool)isIsomorphic(s,t) << endl;

    return 0;
}