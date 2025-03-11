#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> memo;

/**
 * This function checks if two strings are scrambled versions of each other.
 * A string b is considered a scrambled version of string a if it is
 * possible to rearrange the characters in a to form the string b.
 *
 * The function first checks if the two strings are equal. If they are, it
 * returns true. Otherwise, it checks if the two strings have the same length.
 * If they do not, the function returns false. If they do, the function then
 * checks if the length of the strings is 1 or less. If it is, the function
 * returns false. Otherwise, the function checks if the strings are in the
 * memoization table. If they are, the function returns the result from the
 * memoization table. Otherwise, the function calculates the result and stores
 * it in the memoization table.
 *
 * The function then iterates over the characters in the strings, and for each
 * character, it checks two conditions. The first condition is if the first
 * i characters of the string a can be rearranged to form the last i characters
 * of the string b, and if the remaining characters of the string a can be
 * rearranged to form the first n-i characters of the string b. The second
 * condition is if the first i characters of the string a can be rearranged to
 * form the first i characters of the string b, and if the remaining characters
 * of the string a can be rearranged to form the last n-i characters of the
 * string b. If either of these conditions are true, the function returns true.
 * Otherwise, the function returns false.
 */
bool isScramble(string a, string b){
    //base condition
    if(a == b){
        return true;
    }

    if(a.size() != b.size())
        return false;
    if(a.size() <= 1)
        return false;

    int n = a.size();
    bool flag = false;
    string key = a + "_" + b;

    //check if the strings are in the memoization table
    if(memo.find(key) != memo.end()){
        return memo[key];
    }

    //iterate over the characters in the strings
    for(int i=1;i<n;++i){
        //check two conditions
        //swapping
        bool cond1 = isScramble(a.substr(0,i), b.substr(n-i,i)) &&
                        isScramble(a.substr(n-i,i), b.substr(0,n-i));

        //no swapping
        bool cond2 = isScramble(a.substr(0,i), b.substr(0,i)) &&
                        isScramble(a.substr(i,n-i), b.substr(i,n-i));

        //if either of the two conditions are true, return true
        if(cond1 || cond2){
            flag = true;
            break;
        }
    }

    //store the result in the memoization table and return it
    return memo[key] = flag;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()) cout << false;

    if(a.empty() || b.empty()) cout << false;

    cout << isScramble(a,b);
    return 0;

}