#include <iostream>
#include <stack>

using namespace std;

stack<int> st1;
stack<int> st2;

class my_queue {
public:
    void push(int x){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop(){
        int x = st1.top();
        st1.pop();
        return x;
    }

    int peek(){
        return st1.top();
    }

    bool empty(){
        return st1.empty();
    }
};

int main(){
    my_queue* q = new my_queue();
    q->push(1);
    q->push(2);
    q->push(3);
    cout << q->pop() << endl;
    q->push(4);
    cout << q->pop() << endl;
    q->push(5);
    cout << q->peek() << endl;
    return 0;
}