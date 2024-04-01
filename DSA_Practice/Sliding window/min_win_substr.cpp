#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string min_sin_substr(string &str_s, string &str_t){
    /*
        The goal of this function is to find the smallest substring of str_s that contains all the characters in str_t.
        If str_t is empty, return an empty string.
    */
    if(str_t == ""){ // If str_t is empty, return an empty string
        return "";
    }

    unordered_map<char, int> map_s; // map_s will keep track of the frequency of each character in str_s
    unordered_map<char, int> map_t; // map_t will keep track of the frequency of each character in str_t

    int start = 0; // start will keep track of the starting index of the current window
    int end = 0; // end will keep track of the ending index of the current window
    int min_len = INT_MAX; // min_len will keep track of the smallest window size so far
    int req = 0; // req will keep track of the number of distinct characters in str_t
    int current = 0; // current will keep track of the number of distinct characters in the current window that are also in str_t
    int start_idx = 0; // start_idx will keep track of the starting index of the smallest window so far

    for(auto &c : str_t){ // For each character in str_t, increment its frequency in map_t
        map_t[c]++;
        map_s[c] = 0; // Initialize map_s with 0 frequency for each character in str_t
    }

    req = map_t.size(); // req will be the number of distinct characters in str_t

    while(end < str_s.length()){ // Loop through each character in str_s

        char current_char = str_s.at(end); // Get the current character
        if(str_t.find(current_char) != string::npos){ // If the current character is in str_t, increment its frequency in map_s
            map_s[current_char]++;

            if(map_s[current_char] == map_t[current_char]){ // If the current character has the same frequency in map_s and map_t, increment current
                current++;
            }
        }


        while(req == current){ // If the current window contains all the characters in str_t, update min_len and start_idx

            if(end - start + 1 < min_len){ // If the current window is smaller than min_len, update min_len and start_idx
                min_len = end - start + 1;
                start_idx = start;
            }
            char left_char = str_s.at(start); // Get the leftmost character in the current window
            if(str_t.find(left_char) != string::npos){ // If the leftmost character is in str_t, decrement its frequency in map_s
                map_s[left_char]--;
            }

            if(map_s[left_char] < map_t[left_char]){ // If the leftmost character's frequency in map_s is less than its frequency in map_t, decrement current
                current--;
            }

            start++; // Shift the window by 1 character to the right
        }
        end++; // Increment end to move the window by 1 character to the right
    }

    return min_len == INT_MAX ? "" : str_s.substr(start_idx, min_len); // If no such substring exists, return an empty string. Otherwise, return the smallest substring.
}

int main(){


    string str_s, str_t;
    cin >> str_s >> str_t;

    cout << min_sin_substr(str_s, str_t) << endl;

    return 0;
}