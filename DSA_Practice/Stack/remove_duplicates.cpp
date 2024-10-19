#include <iostream>
#include  <stack>

using namespace std;

string RemoveAdjDuplicates(string& str) {
    // Create a stack to store characters
    stack<char> s;

    // Traverse each character in the input string
    for(char c : str) {
        // If the stack is not empty and the top of the stack is the same as the current character
        if(!s.empty() && s.top() == c) {
            // Remove the top character from the stack (since it's a duplicate)
            s.pop();
        } else {
            // Otherwise, push the current character onto the stack
            s.push(c);
        }
    }

    // Create an empty string to store the result
    string res = "";

    // While the stack is not empty
    while(!s.empty()) {
        // Append the character at the top of the stack to the result string
        res += s.top();
        // Remove the top character from the stack
        s.pop();
    }

    // Return the result string
    return res;
}

int main(){
    string str;
    cin >> str;
    cout << RemoveAdjDuplicates(str) << "\n";
    return 0;
}