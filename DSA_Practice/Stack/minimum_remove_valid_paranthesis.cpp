#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string RemoveInvalidParanthesis(string& str) {
    // Initialize a stack to keep track of parentheses and their positions
    stack<pair<char, int>> st;
    // Create a string result initialized with the input string
    string res = str;
    // Get the length of the input string
    int n = str.length();

    // Iterate over each character in the input string
    for (int i = 0; i < n; i++) {
        char c = str[i];
        // If the stack is not empty and the top of the stack is a '('
        // and the current character is ')', we have a valid pair of parentheses
        if (!st.empty() && st.top().first == '(' && c == ')') {
            // Remove the top element from the stack as the pair is valid
            st.pop();
        }
        // If the current character is either '(' or ')', push it onto the stack
        // along with its position in the string
        else if (c == '(' || c == ')') {
            st.push(make_pair(c, i));
        }
    }

    // Remove invalid parentheses from the result string
    // These are the remaining indices in the stack
    while (!st.empty()) {
        // Replace the character at the stored index with a space
        res[st.top().second] = ' ';
        st.pop();
    }

    // Erase all spaces from the result string to finalize it
    res.erase(remove(res.begin(), res.end(), ' '), res.end());

    // Return the modified string with valid parentheses
    return res;
}

int main(){
    string str;
    cin >> str;
    string res = RemoveInvalidParanthesis(str);
    cout << res << endl;
    return 0;
}