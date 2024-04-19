#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief Given two strings, write a function to check if s2 is a
 * permutation of s1.
 * 
 * @param s1 first input string
 * @param s2 second input string
 * @return true if s2 is a permutation of s1, false otherwise
 */
bool checkInclusion(string s1, string s2) {
    // If s1 is longer than s2, it cannot be a permutation
    if (s1.length() > s2.length()) 
        return false;

    // Create two maps to keep track of character counts in both strings
    unordered_map<char, int> mp_s1;
    unordered_map<char, int> mp_s2;

    // Populate the first map with the characters from s1 and their counts
    for(auto &c : s1){
        mp_s1[c]++;
    }

    // Initialize two indices for the sliding window
    int start = 0, end = 0;

    // Initialize a counter to keep track of the number of characters in s2
    // whose count matches the count in s1
    int count = 0;

    // Iterate through s2 until the end of the string
    while(end < s2.length()){
        // Get the character at the current end index
        char end_char = s2[end];

        // If the character is also present in s1
        if(s1.find(end_char) != string::npos){
            // Increment the count of the character in the second map
            mp_s2[end_char]++;

            // If the count of the character in the second map is equal to the
            // count of the character in the first map, then we have found a
            // character whose count matches the count in s1
            if(mp_s2[end_char] == mp_s1[end_char]){
                count++;
            }
        }


        // While the window size is greater than the size of s1, we need to
        // shrink the window by removing characters from the beginning
        while(end - start + 1 > s1.length()){
            // Get the character at the current start index
            char start_char = s2[start];

            // If the character is also present in s1
            if(s1.find(start_char) != string::npos){

                // If the count of the character in the second map is now less
                // than the count of the character in the first map, then we
                // have found a character whose count no longer matches the
                // count in s1, so we need to decrement the count of matched
                // characters
                if(mp_s1[start_char] == mp_s2[start_char]){
                    count--;
                }
                // Decrement the count of the character in the second map
                mp_s2[start_char]--;
            }

            // Keep shifting the window by incrementing the start index
            start++;
        }

        // If we have found a subset of characters in s2 whose count matches
        // the count of characters in s1, then we have found a permutation
        if(count == mp_s1.size()){
            return true;
        }
        // Keep shifting the window by incrementing the end index
        end++;
    }

    // If we have reached the end of the string without finding a permutation,
    // return false
    return false;
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << checkInclusion(s, t);
    return 0;
}