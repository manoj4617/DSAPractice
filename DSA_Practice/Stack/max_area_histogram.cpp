#include <iostream>
#include <ratio>
#include <vector>
#include <stack>

using namespace std;

/**
 * This function takes a vector of heights and returns a vector of indices.
 * The returned vector contains the index of the next smaller element to the
 * left of each element in the input vector. If there is no smaller element to
 * the left, the function returns -1 for that element.
 *
 * The function uses a stack to keep track of the elements that have already
 * been processed. The stack stores the indices of the elements.
 *
 * The loop iterates over the input vector from left to right. For each element,
 * it checks if the stack is empty. If the stack is empty, there is no smaller
 * element to the left of the current element, so the function sets the result
 * for the current element to -1.
 *
 * If the stack is not empty, the function checks if the top of the stack is
 * greater than or equal to the current element. If it is, the function pops the
 * top of the stack and repeats the process until it finds an element that is
 * smaller than the current element or the stack is empty. If the stack is empty,
 * the function sets the result for the current element to -1.
 *
 * If an element is found that is smaller than the current element, the function
 * sets the result for the current element to the index of the top of the stack.
 *
 * Finally, the function pushes the index of the current element onto the stack.
 */
vector<int> nextSmallerLeft(vector<int> heights){
    int n = heights.size();
    stack<int> st;
    vector<int> res(n, 0);
    for(int i=0;i<n;++i){
        /**
         * Check if the stack is empty. If it is, there is no smaller element to
         * the left of the current element, so set the result for the current
         * element to -1.
         */
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        /**
         * If the stack is not empty, the result for the current element is the
         * index of the top of the stack. If the stack is empty, the result for
         * the current element is -1.
         */
        res[i] = (!st.empty()) ? st.top() : -1;
        // Push the index of the current element onto the stack.
        st.push(i);
    }
    return res;
}
/**
 * This function takes a vector of integers and returns a vector of integers.
 * The returned vector contains the index of the next greater element to the
 * left of each element in the input vector. If there is no greater element to
 * the left, the function returns the size of the input vector.
 *
 * The function uses a stack to keep track of the elements that have already been
 * processed. The stack stores the indices of the elements.
 *
 * The loop iterates over the input vector from right to left. For each element,
 * it checks if the stack is empty. If the stack is empty, there is no greater
 * element to the left of the current element, so the function sets the result
 * for the current element to the size of the input vector.
 *
 * If the stack is not empty, the function checks if the top of the stack is
 * greater than or equal to the current element. If it is, the function pops the
 * top of the stack and repeats the process until it finds an element that is
 * greater than the current element or the stack is empty. If the stack is empty,
 * the function sets the result for the current element to the size of the input
 * vector.
 *
 * If an element is found that is greater than the current element, the function
 * sets the result for the current element to the index of the top of the stack.
 *
 * Finally, the function pushes the index of the current element onto the stack.
 */
vector<int> nextSmallerRight(vector<int> heights){
    int n = heights.size();
    stack<int> st;
    vector<int> res(n, n);
    for(int i=n-1;i>=0;--i){
        /**
         * Check if the stack is empty. If it is, there is no greater element to
         * the left of the current element, so set the result for the current
         * element to the size of the input vector.
         */
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        /**
         * If the stack is not empty, the result for the current element is the
         * index of the top of the stack. If the stack is empty, the result for
         * the current element is the size of the input vector.
         */
        res[i] = (!st.empty()) ? st.top() : n;
        // Push the index of the current element onto the stack.
        st.push(i);
    }
    return res;
}
/**
 * This function takes a vector of integers and returns an integer. The returned
 * integer is the largest rectangle area that can be formed from the given
 * heights.
 *
 * The function works by first finding the next smaller element to the left and
 * next greater element to the right of each element in the input vector. It
 * then calculates the area of the rectangle that can be formed using each
 * element as the minimum height and the width as the difference between the
 * indices of the next greater element to the right and the next smaller element
 * to the left. The maximum of these areas is then returned.
 */
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    /**
     * Find the next smaller element to the left of each element in the input
     * vector.
     */
    vector<int> nsl = nextSmallerLeft(heights);
    /**
     * Find the next greater element to the right of each element in the input
     * vector.
     */
    vector<int> nsr = nextSmallerRight(heights);
    int maxArea = 0;
    /**
     * Iterate over the input vector and for each element, calculate the area of
     * the rectangle that can be formed using the current element as the minimum
     * height and the width as the difference between the indices of the next
     * greater element to the right and the next smaller element to the left.
     */
    for(int i=0;i<n;++i){
        int width = nsr[i] - nsl[i] - 1;
        maxArea = max(maxArea, width * heights[i]);
    }
    return maxArea;
}


/**
 * This function takes a vector of integers and returns an integer. The returned
 * integer is the largest rectangle area that can be formed from the given
 * heights.
 *
 * The function works by using a stack to keep track of the elements that have
 * already been processed. The stack is used to store the indices of the
 * elements.
 *
 * The loop iterates over the input vector. For each element, it checks if the
 * top of the stack is greater than or equal to the current element. If it is,
 * the function pops the top of the stack and repeats the process until it finds
 * an element that is smaller than the current element or the stack is empty. If
 * the stack is empty, the function sets the width to the current index and
 * calculates the area of the rectangle that can be formed using the current
 * element as the minimum height and the width as the difference between the
 * current index and the top of the stack. The maximum of these areas is then
 * updated.
 *
 * After the loop, the function checks if the stack is not empty. If it is not
 * empty, the function pops the top of the stack and calculates the area of the
 * rectangle that can be formed using the current element as the minimum height
 * and the width as the difference between the size of the input vector and the
 * top of the stack. The maximum of these areas is then updated.
 *
 * Finally, the function returns the maximum area.
 */
int largestRectangleArea2(vector<int>& heights){
    int n = heights.size();
    stack<int> st;
    st.push(-1);
    int max_area = 0;

    for(int i=0;i<n;++i){
        /**
         * Check if the top of the stack is greater than or equal to the current
         * element. If it is, pop the top of the stack and repeat the process
         * until an element is found that is smaller than the current element or
         * the stack is empty.
         */
        while(st.top() != -1 && heights[st.top()] >= heights[i]){
            int curHeight = heights[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            /**
             * Calculate the area of the rectangle that can be formed using the
             * current element as the minimum height and the width as the
             * difference between the current index and the top of the stack.
             */
            max_area = max(max_area, curHeight * width);
        }
        /**
         * Push the index of the current element onto the stack.
         */
        st.push(i);
    }

    /**
     * Check if the stack is not empty. If it is not empty, pop the top of the
     * stack and calculate the area of the rectangle that can be formed using the
     * current element as the minimum height and the width as the difference
     * between the size of the input vector and the top of the stack.
     */
    while(st.top() != -1){
        int curHeight = heights[st.top()];
        st.pop();
        int width = n - st.top() - 1;
        max_area = max(max_area, curHeight * width);
    }

    return max_area;
}

int main(){

    vector<int> heights = {2,1,5,6,2,3};
    // cout << largestRectangleArea(heights);
    cout << largestRectangleArea2(heights);

    return 0;
}