#include <iostream>
#include <stack>

using namespace std;
/**
 * Checks if a given string is a valid sequence of parentheses.
 * The function uses a stack to keep track of the opening parentheses.
 * For each closing parenthesis encountered, it checks if the top of
 * the stack contains the corresponding opening parenthesis. If it does,
 * it pops the opening parenthesis from the stack. If it doesn't, it
 * returns false. If the stack is empty at the end of the string, it
 * returns true. Otherwise, it returns false.
 */
bool IsValid(string s) {
    
    /* Create an empty stack */
    stack<char> st;
    
    /* Iterate over each character in the string */
    for(auto& c : s){
      if(c == '(' || c == '{' || c == '['){

        /* If the character is an opening parenthesis, push it onto the stack */
        st.push(c);
      }
     else if(c == ')' || c == '}' || c == ']'){

        /* If the character is a closing parenthesis, check if the stack is empty */
        if(st.empty()){
          return false;
        }

        /* If the stack is not empty, pop the top element and compare it with the
         * closing parenthesis. If they don't match, return false */
        char t = st.top();
        st.pop();
        if((c == ')' && t != '(') ||
        (c == '}' && t != '{') ||
        (c == ']' && t != '[')){
          return false;
        }
      }
    }

    /* If the stack is empty at the end of the string, return true */
    if(st.empty()) return true;

    /* Otherwise, return false */
    return false;
}


int main(){
    string str;
    cin >> str;

    cout << IsValid(str);
    return 0;
}