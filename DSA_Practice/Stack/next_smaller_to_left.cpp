#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * This function takes a vector of integers and returns a vector of integers.
 * The returned vector contains the next smaller element to the left of each
 * element in the input vector. If there is no smaller element to the left, the
 * function returns -1 for that element.
 *
 * The function uses a stack to keep track of the elements that have already been
 * processed. The stack is used to efficiently find the next smaller element to
 * the left of each element in the input vector.
 *
 * The function iterates over the input vector from left to right. For each
 * element, it checks if the stack is empty. If the stack is empty, there is no
 * smaller element to the left of the current element, so the function pushes
 * -1 onto the result vector.
 *
 * If the stack is not empty, the function checks if the top of the stack is
 * smaller than the current element. If it is, the function pushes the top of the
 * stack onto the result vector.
 *
 * If the top of the stack is not smaller than the current element, the function
 * pops the top of the stack and repeats the process until it finds an element
 * that is smaller than the current element or the stack is empty. If the stack
 * is empty, the function pushes -1 onto the result vector. If an element is
 * found that is smaller than the current element, the function pushes that
 * element onto the result vector.
 */
vector<int> nect_smaller_to_left(vector<int>& nums){
    int len = nums.size();
    vector<int> res;
    stack<int> st;

    for(int i=0;i<len;++i){
        /**
         * If the stack is empty, there is no smaller element to the left of the
         * current element, so push -1 onto the result vector.
         */
        if(st.size() == 0){
            res.push_back(-1);
        }
        /**
         * Check if the top of the stack is smaller than the current element. If
         * it is, push the top of the stack onto the result vector.
         */
        else if(st.size() > 0 && st.top() < nums[i]){
            res.push_back(st.top());
        }
        /**
         * If the top of the stack is not smaller than the current element, pop
         * the top of the stack and repeat the process until an element is found
         * that is smaller than the current element or the stack is empty. If the
         * stack is empty, push -1 onto the result vector. If an element is found
         * that is smaller than the current element, push that element onto the
         * result vector.
         */
        else if(st.top() > 0 && st.top() >= nums[i]){
            while(st.top() > 0 && st.top() >= nums[i]){
                st.pop();
            }
            if(st.size() == 0){
                res.push_back(-1);
            }
            else{
                res.push_back(st.top());
            }
        }
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

    vector<int> res = nect_smaller_to_left(nums);
    for(int &i : res){
        cout << i << " ";
    }

    return 0;
}