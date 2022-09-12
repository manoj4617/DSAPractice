#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;
Node* last = nullptr;

void insert_last(int val){
    Node* t = new Node;
    t->data = val;
    t->next = nullptr;
    
    if(head == nullptr){
        head = t;
        last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

void display(struct Node* p){
    while(p != nullptr){
        cout << p->data << "->" << flush;
        p = p->next;
    }
}

// int main(){

//     insert_last(10);
//     insert_last(11);
//     insert_last(12);
//     insert_last(13);
//     insert_last(14);
//     insert_last(14);
//     insert_last(14);

//     display(head);
//     return 0;
// }