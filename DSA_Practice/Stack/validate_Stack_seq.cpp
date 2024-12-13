#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * This function validates whether a given sequence of pushed and popped elements
 * can happen in a stack.
 *
 * The function takes two vectors of integers, pushed and popped, which represent
 * the sequence of elements that are pushed and popped from a stack.
 *
 * The function returns a boolean indicating whether the given sequence is a valid
 * sequence of pushed and popped elements.
 */
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    /**
     * The variable len is used to keep track of the size of the pushed vector.
     * This is used to iterate over the pushed vector and to keep track of the
     * number of elements that have been pushed and popped.
     */
    int len = pushed.size();
    
    /**
     * The variable j is used to keep track of the current index of the popped
     * vector. This is used to compare the top of the stack with the current
     * element in the popped vector.
     */
    int j = 0;
    
    /**
     * The stack st is used to keep track of the elements that have been pushed
     * but not yet popped.
     */
    stack<int> st;
    
    /**
     * This loop iterates over the pushed vector and pushes each element onto the
     * stack.
     */
    for(int& num : pushed){
        st.push(num);
        
        /**
         * This while loop continues to pop elements from the stack until the top
         * of the stack is not equal to the current element in the popped vector
         * or until the stack is empty.
         */
        while(!st.empty() && j < len && st.top() == popped[j]){
            st.pop();
            j++;
        }
    }
    
    /**
     * If the stack is empty and the popped vector has been fully iterated over,
     * then the function returns true, indicating that the sequence is valid.
     */
    if(j == len){
        return true;
    }
    
    /**
     * Otherwise, the function returns false, indicating that the sequence is not
     * valid.
     */
    return false;
}

int main(){
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};

    cout << validateStackSequences(pushed, popped);
    return 0;
}