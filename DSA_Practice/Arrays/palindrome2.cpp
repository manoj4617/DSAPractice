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