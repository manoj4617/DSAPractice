#include<iostream>
#include<queue>
#include<stack>
#include "tree.h"
#include<iostream>

using namespace std;

void Tree::create_tree(){
    Node *p, *q;
    queue<Node*> node_q;

    cout<<"\nEnter root value";
    int root_val;
    cin >> root_val;
    Node *t;

    root = t->create_new_node(root_val);

    node_q.push(root);

    while(!node_q.empty()){
        int node_val;
        p = node_q.front();
        node_q.pop();
        //creating left child
        cout<<"\nEnter left child value of " << p->data;
        cin >> node_val;
        if(node_val != -1){
            Node *n = t->create_new_node(node_val);
            p->left_child = n;
            node_q.push(n);
        }
        else{
            break;
        }

        // creating right child
        cout<<"\nEnter right child value of " << p->data;
        cin >> node_val;
        if(node_val != -1){
            Node *n = t->create_new_node(node_val);
            p->right_child = n;
            node_q.push(n);
        }else {
            break;
        }
    }
}

void Tree::pre_order(Node* p){
    if(p){
        cout<< p->data << " ";
        pre_order(p->left_child);
        pre_order(p->right_child);
    }
}

void Tree::itr_pre_order(Node *p){
    stack<Node*> st;

    while(!st.empty() || p != nullptr){
        if(p != nullptr){
            cout << p->data << " ";
            st.push(p);
            p = p->left_child;
        }
        else{
            p = st.top();
            st.pop();
            p = p->right_child;
        }
    }
}

void Tree::post_order(Node *p){

    if(p){
        post_order(p->left_child);
        post_order(p->right_child);
        cout<<p->data << " ";
    }
}

void Tree::in_order(Node *p){

    if(p){
        in_order(p->left_child);
        cout<<p->data << " ";
        in_order(p->right_child);
    }
}

void Tree::itr_in_order(Node *p){
    stack<Node*> st;

    while(p != nullptr || !st.empty()){
        if(p != nullptr){
            st.push(p);
            p = p->left_child;
        }
        else{
            p = st.top();
            cout << p->data << " ";
            st.pop();
            p = p->right_child;
        }
    }
}

void Tree::level_order(Node *p){
    queue<Node*> q;

    if(p == nullptr){
        return;
    }

    q.push(p);

    while(!q.empty()){
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if(node->left_child != nullptr)
            q.push(node->left_child);
        if(node->right_child != nullptr){
            q.push(node->right_child);
        }
    }
}

int Tree::find_height(Node *p){
    int x = 0, y = 0;

    if(p == nullptr)
        return 0;
    
    x = find_height(p->left_child);
    y = find_height(p->right_child);

    return x > y ? x + 1 : y + 1;
}

void left_view_wrapper(Node *p, int level, int *max_level){
    if(!p)
        return;
    
    if(*max_level < level){
        //cout<< "\n Maxlevel: " << *max_level << "\nCurrent Level: " << level << endl; 
        cout << p->data << " ";
        *max_level = level;
    }


    left_view_wrapper(p->left_child,level+1,max_level);
    left_view_wrapper(p->right_child,level+1,max_level);
}

void Tree::left_view(Node *p){
    int max_level = 0;
    left_view_wrapper(p,1,&max_level);
}



int main(){

    Tree bt;
    bt.create_tree();
    cout << endl;
    bt.left_view(bt.root);
    
    // cout<<"Pre-order\n";
    // bt.itr_pre_order(bt.root);
    // cout << endl;

    // cout<<"Post-order\n";
    // bt.post_order(bt.root);
    // cout << endl;

    // cout<<"In-order\n";
    // bt.in_order(bt.root);
    // cout << endl;

    // cout<<"Level-order\n";
    // bt.level_order(bt.root);
    // cout << endl;


    return 0;
}