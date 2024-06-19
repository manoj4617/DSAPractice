#include<iostream>
#include<string>

using namespace std;

string expand(string str, int low, int high)
{
    while (low >= 0 && high < str.length() && (str[low] == str[high])) {
        low--, high++;       
    }
    return str.substr(low + 1, high - low - 1);
}
 
// This function finds the longest palindromic substring in a given string
// The time complexity is O(n^2), where n is the length of the input string
// The space complexity is O(1), as we only need to maintain two pointers
// and two variables for the current substring and the maximum substring found so far

string longestPalindromicSubstring(string str)
{
    // If the input string is empty, return an empty string
    if (str.length() == 0) {
        return str;
    }
    
    // Initialize the maximum palindromic substring found so far
    string max_str = "", curr_str;
 
    // Initialize the length of the maximum substring found so far
    int max_length = 0, curr_length;
 
    // Iterate through each character in the input string
    for (int i = 0; i < str.length(); i++)
    {
    
        // Expand the current character as a center of a palindromic substring
        // and check if it is longer than the current maximum substring
        curr_str = expand(str, i, i);
        curr_length = curr_str.length();
 
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
 
        // Expand the current character as a center of a palindromic substring with two characters
        // and check if it is longer than the current maximum substring
        curr_str = expand(str, i, i + 1);
        curr_length = curr_str.length();
 
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
    }
 
    // Return the longest palindromic substring found in the input string
    return max_str;
}
 
int main()
{
    string str;
    getline(cin,str);
 
    cout <<longestPalindromicSubstring(str);
 
    return 0;
}