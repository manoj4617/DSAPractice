#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find all occurrences of anagrams of a given string 'p' in a 
// given string 's'.
//
// The approach is based on a Sliding Window technique. We use two hashmaps,
// one 'mp_p' to store the frequency of each character in 'p' and another
// 'mp_s' to store the frequency of each character of the current window of
// 's' that is being processed.
//
// We start two indexes, 'start' and 'end', at 0 and increment 'end' while 
// keeping 'end - start + 1 <= p.length()'. If the character at 'end' is
// present in 'p', we increment the frequency of that character in 'mp_s'.
//
// If the frequency of a character in 'mp_s' is less than or equal to its
// frequency in 'mp_p', we increment the 'count' of valid characters in
// 'mp_s'.
//
// If the 'count' becomes equal to 'p.length()', we have found an anagram
// of 'p' in 's' from index 'start' to index 'end'. So we push the starting
// index of the current window into the 'ans' vector and move the 'start' index
// forward by 1.
//
// We keep doing this until we have processed all characters of 's'.
//
// Time complexity: O(n), where 'n' is the length of 's'
// Space complexity: O(m), where 'm' is the number of distinct characters
//                    in 'p'
vector<int> findAnagrams(string s, string p){
    int start = 0, end = 0;

    vector<int> ans;

    unordered_map<char, int> mp_p; // To store freq of chars in 'p'
    unordered_map<char, int> mp_s; // To store freq of chars in current window

    int count = 0; // To keep track of # of valid chars in 'mp_s'

    // Initialize 'mp_p' with frequency of each char in 'p'
    for(auto &c : p){
        mp_p[c]++;
    }

    // Keep expanding the right side of the window, while keeping
    // the left side fixed until we cover the entire 's'
    while(end < s.length()){
        char c = s[end]; // Current char in 's'

        // If current char is in 'p', increment its freq in 'mp_s'
        if(mp_p.find(c) != mp_p.end()){
            mp_s[c]++;

            // If freq of current char in 'mp_s' is <= its freq in 'mp_p'
            // we have a valid char, so increment 'count'
            if(mp_s[c] <= mp_p[c]){
                count++;
            }
        }

        // Keep shrinking the left side of the window while its size
        // is greater than 'p.length()'
        while(end - start + 1 > p.length()){
            char start_char = s[start]; // Char at starting index of window

            // If char at starting index is in 'p', decrement its freq in 'mp_s'
            if(mp_p.find(start_char) != mp_p.end()){
                mp_s[start_char]--;

                // If freq of char at starting index is now < its freq in 'mp_p'
                // we have reduced the valid # of chars in 'mp_s' by 1, so
                // decrement 'count'
                if(mp_s[start_char] < mp_p[start_char]){
                    count--;
                }
            }

            // Move starting index forward by 1
            start++;
        }

        // If we have seen all the chars in 'p' in 'mp_s', we have found
        // an anagram of 'p' in 's' from index '
        if(count == p.length()){
           ans.push_back(start);
        }

        end++;

    }   

    return ans; 
}

int main(){

    string s, p;
    cin >> s >> p;
    vector<int> ans = findAnagrams(s, p);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}