#include <cstddef>
#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr){}
    Node(int val, Node* nxt) : data(val) , next(nullptr) {}
};

Node* head = nullptr;
Node* last = nullptr;

void sorted_insert(Node* p, int val){
    Node* t,*q = nullptr;
    t = new Node;
    t->data = val;
    t->next = nullptr;

    if(head == nullptr)
        head = t;
    else{
        while(p && p->data < val){
            q = p;
            p = p->next;
        }
        if(p == head){
            t->next = head;
            head = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

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

int delete_from_first(struct Node* del){
    // if(del == nullptr)
    //     return;
    Node* p = head;
    int x = del->data;
    head = del->next;
    delete p;
    return x;
}

int delete_from_anywhere(struct Node* del, int pos){
    Node* p = head;
    Node* q = nullptr;

    for(int i=0;i<pos-1 && p;++i){
        q = p;
        p = p->next;
    }

    q->next = p->next;
    int x = p->data;
    delete p;

    return x;
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