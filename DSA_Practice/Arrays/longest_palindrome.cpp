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

string longestPalindrome(string s){
    int max_len = 1;
    int start = 0;
    for(int i=1;i<s.length();++i){
        bool even = false;
        int len2 = 0;
        int len1 = 0;

        if(s[i-1] == s[i]){
            len2 = expand_palindrome(s, i - 1, i);
            even = true;
        }
        else{
            len1 = expand_palindrome(s, i, i);
        }
        int len = max(len1, len2);
        if(len > max_len){
            max_len = len;
            if(even){
                start = (i-1) - (max_len - 1)/2; 
            }else{
                start = i - max_len/2;
            }
        }
    }
    return s.substr(start, max_len);
}

int main(){

    string s;

    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}