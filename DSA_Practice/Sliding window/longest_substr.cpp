#include<iostream>
#include<map>
#include<string>

using namespace std;

int longest_sub_str(string str) {
    // Function to find the length of the longest substring with no repeating characters
    // Time Complexity: O(n)
    // Space Complexity: O(m) where m is the number of distinct characters in the input string

    map<char, int> mp; // map to keep track of the number of occurrences of each character

    int start = 0, end = 0; // two pointers to track the start and end indices of the current substring
    int len = str.length(); // length of the input string
    int max_len = INT_MIN; // maximum length of a substring seen so far

    while (end < len) { // loop through each character in the input string

        mp[str[end]]++; // increment the count of the current character in the map

        if (mp[str[end]] > 1) { // if the current character has already occurred once

            while (mp[str[end]] > 1) { // keep reducing the count of the current character until it becomes 1
                mp[str[start]]--;
                start++; // increment the start index
            }
        }

        if (end - start + 1 > max_len) { // if the length of the current substring is greater than the maximum length seen so far
            max_len = end - start + 1; // update the maximum length
        }
        end++; // increment the end index
    }

    return max_len; // return the maximum length + 1
}

int main(){

    string str;
    getline(cin, str);

    cout << longest_sub_str(str) << endl;
    return 0;
}