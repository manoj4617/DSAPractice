#include <iostream>
#include <string>

using namespace std;

int expand_palindrome(string s, int left , int right){
    while(left >= 0 && right < s.length() && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s) {
    // This function finds the longest palindromic substring in the given string.
    // Time complexity: O(n^2), where n is the length of the input string.
    // Space complexity: O(1).

    int max_len = 1;  // The maximum length of the palindromic substring found so far.
    int start = 0;   // The starting index of the longest palindromic substring.

    for (int i = 0; i < s.length(); ++i) {  // For each index in the string,
        
        int len2 = 0;  // The length of the palindromic substring centered at i and i+1.
        int len1 = 0;  // The length of the palindromic substring centered at i and i.

        len1 = expand_palindrome(s, i, i);  // Expand from the center (i, i) to the left and right.
        len2 = expand_palindrome(s, i, i + 1);

        int len = max(len1, len2);  // The maximum of the two lengths.

        if (len > max_len) {  // If the current maximum is greater than the previous maximum,
            max_len = len;  // Update the maximum length and starting index.
            start = i - (max_len - 1) / 2;
        }
    }
    return s.substr(start, max_len);  // Return the substring corresponding to the maximum length.
}

int main(){

    string s;

    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}