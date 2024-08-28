#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// Function to remove duplicates from a given string
// The idea behind this logic is to use a bitmask to keep track of the characters that have been encountered so far
// and a stack to keep track of the characters in the final sorted string
string RemoveDuplicates(string s){
    int bitmask = 0; // bitmask to keep track of the characters that have been encountered so far
    unordered_map<char, int> mp; // map to keep track of the frequency of each character in the string
    stack<char> st; // stack to keep track of the characters in the final sorted string

    // Iterate through the string and update the frequency of each character
    for(char& c : s){
        mp[c]++;
    }

    // Iterate through the string again and process each character
    for(char& c : s){
        mp[c]--; // decrement the frequency of the character
        int exists = bitmask & (1 << (c - 'a')); // check if the character has already been encountered
        if(exists > 0){ // if the character has already been encountered, skip it
            continue;
        }

        // while the stack is not empty and the top character is greater than the current character
        // and the frequency of the top character is greater than 0, pop the top character from the stack
        while(!st.empty() && st.top() > c && mp[st.top()] > 0){
            bitmask &= ~(1 << (st.top() - 'a')); // remove the bit corresponding to the top character from the bitmask
            st.pop();
        }

        // push the current character onto the stack
        st.push(c);
        bitmask |= (1 << (c-'a')); // set the bit corresponding to the current character in the bitmask
    }

    // construct the final sorted string by popping characters from the stack
    string res;
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }

    return res;
}

int main(){
    string s;
    cin >> s;
    string r = RemoveDuplicates(s);
    cout << r;
    return 0;
}