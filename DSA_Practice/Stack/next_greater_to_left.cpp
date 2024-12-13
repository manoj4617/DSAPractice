#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and returns a vector of integers.
 * The returned vector contains the next greater element to the left of each
 * element in the input vector. If there is no greater element to the left, the
 * function returns -1 for that element.
 *
 * The function uses a stack to keep track of the elements that have already been
 * processed. The stack is used to efficiently find the next greater element to
 * the left of each element in the input vector.
 *
 * The function iterates over the input vector from left to right. For each
 * element, it checks if the stack is empty. If the stack is empty, there is no
 * greater element to the left of the current element, so the function pushes
 * -1 onto the result vector.
 *
 * If the stack is not empty, the function checks if the top of the stack is
 * greater than the current element. If it is, the function pushes the top of
 * the stack onto the result vector.
 *
 * If the top of the stack is not greater than the current element, the function
 * pops the top of the stack and repeats the process until it finds an element
 * that is greater than the current element or the stack is empty. If the stack
 * is empty, the function pushes -1 onto the result vector. If an element is
 * found that is greater than the current element, the function pushes that
 * element onto the result vector.
 */
vector<int> next_greater_to_left(vector<int>& nums){
    int len = nums.size();
    stack<int> st;
    vector<int> res;

    for(int i=0;i<len;++i){
        /**
         * Check if the stack is empty. If it is, there is no greater element to
         * the left of the current element, so push -1 onto the result vector.
         */
        if(st.size() == 0)
        {
            res.push_back(-1);
        }
        /**
         * Check if the top of the stack is greater than the current element. If
         * it is, push the top of the stack onto the result vector.
         */
        else if(st.size() > 0 && st.top() > nums[i]){
            res.push_back(st.top());
        }
        /**
         * Check if the top of the stack is not greater than the current element.
         * If it is, pop the top of the stack and repeat the process until an
         * element is found that is greater than the current element or the stack
         * is empty.
         */
        else if(st.size() > 0 && st.top() <= nums[i]){
            while(st.size() > 0 && st.top() <= nums[i]){
                st.pop();
            }
            /**
             * Check if the stack is empty. If it is, push -1 onto the result
             * vector. If an element is found that is greater than the current
             * element, push that element onto the result vector.
             */
            if(st.size() == 0){
                res.push_back(-1);
            }
            else{
                res.push_back(nums[i]);
            }
        }
        /**
         * Push the current element onto the stack to keep track of the elements
         * that have already been processed.
         */
        st.push(nums[i]);
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }

    vector<int> res = next_greater_to_left(nums);
    for(int &i : res){
        cout << i << " ";
    }

    return 0;
}