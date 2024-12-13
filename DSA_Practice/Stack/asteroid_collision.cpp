#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * This function takes a vector of asteroid velocities and returns a vector of
 * asteroid velocities that survive a collision. The function uses a stack to
 * keep track of the asteroids that are moving to the right (i.e. positive
 * velocities). The function iterates over the input vector and checks if the
 * current asteroid is colliding with any of the asteroids in the stack. If it
 * is, it checks if the current asteroid is destroyed or if it destroys one or
 * more of the asteroids in the stack. If the current asteroid is destroyed, it
 * is skipped. If the current asteroid destroys one or more of the asteroids in
 * the stack, they are removed from the stack. The function then pushes the
 * current asteroid onto the stack. After the iteration is complete, the
 * function pops all the elements from the stack and pushes them onto a result
 * vector in reverse order. The function returns the result vector.
 */
vector<int> asteroidCollision(vector<int>& asteroids){
    stack<int> col_st;
    for(int& a : asteroids){
        bool destroyed = false;

        /**
         * Check if the current asteroid is colliding with any of the asteroids
         * in the stack. If it is, check if the current asteroid is destroyed or
         * if it destroys one or more of the asteroids in the stack.
         */
        while(!col_st.empty() && a < 0 && col_st.top() > 0){
            // If the absolute value of the current asteroid is greater than the
            // top of the stack, the top of the stack is destroyed.
            if(abs(a) > col_st.top()){
                col_st.pop();
            }
            // If the absolute value of the current asteroid is equal to the
            // top of the stack, both asteroids are destroyed.
            else if(abs(a) == col_st.top()){
                col_st.pop();
                destroyed = true;
                break;
            }
            // If the absolute value of the current asteroid is less than the
            // top of the stack, the current asteroid is destroyed.
            else{
                destroyed = true;
                break;
            }
        }

        // If the current asteroid is not destroyed, push it onto the stack.
        if(!destroyed){
            col_st.push(a);
        }
    }

    // Create a result vector to store the surviving asteroids.
    vector<int> res;

    // Pop all the elements from the stack and push them onto the result vector
    // in reverse order.
    while(!col_st.empty()){
        res.push_back(col_st.top());
        col_st.pop();
    }

    // Reverse the result vector.
    reverse(res.begin(), res.end());

    // Return the result vector.
    return res;
}

int main(){

    vector<int> asteroids = {5 ,10, -5};
    vector<int> res = asteroidCollision(asteroids);
    if(res.size() != 0){
        for(int& r : res){
            cout << r << " ";
        }
    }
    else {
        cout << " ";
    }

    return 0;
}
