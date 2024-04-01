#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find the length of the longest substring with no repeating characters
// Time Complexity: O(n)
// Space Complexity: O(m) where m is the number of distinct characters in the input string
int max_non_rep_sub_str(string str){
    // start and end are two pointers to track the start and end indices of the current
    // substring, respectively
    int start = 0 , end = 0;

    // max_len is the maximum length of a substring seen so far
    int max_len = 0;

    // winlen is the length of the current substring
    int winlen = 0;

    // mp is a hashmap to keep track of the number of occurrences of each character
    // in the current substring
    unordered_map<char,int> mp;


    // Iterate through each character in the input string
    while(end < str.length()){
        // If the current character is not already in the map (i.e. it has not
        // occurred in the current substring before), add it to the map
        if(mp.find(str[end]) == mp.end()){
            mp[str[end]] = end;
        }
        // If the current character has already occurred in the map, it means
        // that we have found a repeated character in the current substring
        else{
            // If the index of the repeated character is within the current
            // substring (i.e. it has not yet wrapped around to the beginning of
            // the string), then we need to shrink the current substring
            if(mp[str[end]] >= start && mp[str[end]] <= end){
                // Calculate the length of the current substring
                winlen = end - start;

                // If the length of the current substring is greater than the
                // maximum length seen so far, update max_len
                if(max_len < winlen){
                    max_len = winlen;
                }

                // Update the start index of the current substring to be
                // mp[str[end]] + 1 (i.e. the index of the repeated character + 1)
                start = mp[str[end]] + 1;
            }

            // Add the current character to the map (since it has not occurred
            // before in the current substring)
            mp[str[end]] = end;
        }

        // Increment the end index of the current substring
        end++;
    }

    // If the length of the current substring is greater than the maximum
    // length seen so far, update max_len
    if(end - start > max_len){
        max_len = end - start;
    }

    // Return the maximum length of a substring with no repeating characters
    return max_len;
}


int main(){

    string str;

    cin >> str;
    cout << max_non_rep_sub_str(str);

    return 0;
}