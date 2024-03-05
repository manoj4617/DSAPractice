#include<iostream>
#include"ll_inserting_last.h"

using namespace std;

Node* first = nullptr;
Node* second = nullptr;
Node* third = nullptr;

void create_node1(int A[], int n){
    Node* t , *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for(int i=1;i<n;++i){
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void create_node2(int B[], int n){
    Node* t , *last;
    second = new Node;
    second->data = B[0];
    second->next = nullptr;
    last =second;

    for(int i=1;i<n;++i){
        t = new Node;
        t->data = B[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void merge_lists(struct Node* f, struct Node* s){
    Node* last;
    if(f->data < s->data){
        last = third = f;
        f = f->next;
        last->next = nullptr;
    } 
    else{
        last = third = s;
        s = s->next;
        last->next = nullptr;
    }

    while(f != nullptr && s != nullptr){
        if(f->data < s->data){
            last->next = f;
            last = f;
            f = f->next;
            last->next = nullptr;
        }   
        else{
            last->next = s;
            last = s;
            s = s->next;
            last->next = nullptr;
        }
    }
    if(f != nullptr){
        last->next = f;
        f = f->next;
    }
    if(s != nullptr){
        last->next = s;
        s = s->next;
    }
}

int main(){
    int A[] = {2,4,8,9,10};
    int B[] = {4,12,14,24};

    create_node1(A,5);
    create_node2(B,4);
    merge_lists(first, second);
    display(third);
    return 0;
}