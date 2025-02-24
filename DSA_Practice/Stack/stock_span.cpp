#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and returns a vector of integers.
 * The returned vector contains the span of each element in the input vector.
 * The span of an element is the number of elements to its left that are smaller
 * than it.
 *
 * This function uses a stack to keep track of the elements that have already been
 * processed. The stack stores the indices of the elements.
 *
 * The loop iterates over the input vector. For each element, it checks if the
 * stack is empty. If the stack is empty, the span of the current element is
 * equal to its index plus one.
 *
 * If the stack is not empty, the function checks if the top of the stack is
 * smaller than or equal to the current element. If it is, the function pops the
 * top of the stack and repeats the process until it finds an element that is
 * greater than the current element or the stack is empty. If the stack is empty,
 * the span of the current element is equal to its index plus one.
 *
 * If an element is found that is greater than the current element, the function
 * pushes the index of the current element onto the stack and sets the span of
 * the current element to the difference between its index and the index of the
 * top of the stack.
 *
 * The function returns the result vector.
 */
vector<int> stockSpan(vector<int> arr) {
    stack<int> st;
    vector<int> res(arr.size());
    for(int i=0;i<arr.size();++i) {
        // While the stack is not empty and the top of the stack is smaller than
        // or equal to the current element, pop the top of the stack and repeat
        // the process until we find an element that is greater than the current
        // element or the stack is empty.
        while(st.size() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        // The span of the current element is equal to its index plus one if the
        // stack is empty, or the difference between its index and the index of
        // the top of the stack if the stack is not empty.
        res[i] = st.size() ? i - st.top() : i + 1;
        // Push the index of the current element onto the stack.
        st.push(i);
    }
    // Return the result vector.
    return res;
}

int main(){
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockSpan(arr);
    for(int &i : res) cout << i << " ";
    return 0;
}