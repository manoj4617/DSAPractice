#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * This function is the recursive helper function for the Decode function.
 * It takes a string of digits and an index into that string, and it
 * counts the number of ways to decode the string from the given index
 * to the end of the string. The function uses backtracking to explore
 * all the possible decoding of the string, and the count of ways to
 * decode the string is stored in the count reference parameter.
 *
 * @param s The string of digits to be decoded.
 * @param i The index into the string.
 * @param count The count of ways to decode the string from the given
 * index to the end of the string.
 */
void Backtrack(string& s, int i, int& count){

    // The base case: if the index is at the end of the string, we have
    // found one way to decode the string, so increment the count by 1.
    if(i == s.size()){
        count++;
        return;
    }

    // If the current character is '0', there is no way to decode the
    // string from the current index to the end of the string, so we
    // return immediately.
    if(s[i] == '0'){
        return;
    }

    // If the current character is not '0', we have one way to decode
    // the string: to decode the current character as a single digit.
    // So we recurse with the next index.
    if(s[i] != '0'){
        Backtrack(s, i+1, count);
    }

    // If the current character and the next character form a valid
    // two-digit number, we have another way to decode the string: to
    // decode the current character and the next character as a single
    // two-digit number. So we recurse with the index incremented by 2.
    if((s.size() - i >= 2) && (s[i] != '0')){
        int n = atoi(s.substr(i,2).c_str());
        if(n <= 26){
            Backtrack(s, i + 2, count);
        }
    }
}

int Decode(string& s){
    int count = 0;
    Backtrack(s, 0, count);
    return count;
}

int main(){
    string s;
    cin >> s;
    cout << Decode(s);
    return 0;
}