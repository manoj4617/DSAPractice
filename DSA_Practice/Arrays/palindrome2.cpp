#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string& str, int i, int j){
    while(i < j){
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// This function checks if the given string can be a palindrome
// by checking if there are any characters that are different
// from their corresponding characters in the reverse of the string.
//
// Algorithm:
// 1. Keep two pointers, start and end, pointing to the first and last
//    characters of the string, respectively.
// 2. If the characters at start and end are the same, increment start
//    and decrement end, and move on to the next iteration.
// 3. If the characters at start and end are different, call isPalindrome
//    function twice. The first call is to check if the substring from
//    start+1 to end is a palindrome. The second call is to check if the
//    substring from start to end-1 is a palindrome.
// 4. If either of the two calls to isPalindrome returns true, return true.
// 5. If both calls return false, return false.
//
// Note that the loop continues till start >= end, which means when start
// and end meet in the middle, we have checked all possible pairs of
// characters.
//
bool can_be_palindrome(string &str){

    int start = 0;
    int end = str.length() - 1;

    while(start < end){
        if(str[start] != str[end]){
            return isPalindrome(str, start+1, end) || isPalindrome(str,start, end-1);
        }
        start++;
        end--;
    }

    return true;
}

int main(){
    string str;
    getline(cin, str);
    if(can_be_palindrome(str)){
        cout << "Can be palindrome";
    } else {
        cout << "Cannot be palindrome";
    }
    return 0;
}