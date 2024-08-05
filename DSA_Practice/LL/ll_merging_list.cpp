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

/*
This function merges two sorted linked lists and returns a third linked list which is sorted.
It takes two nodes as input: f and s.
f and s are the heads of the two linked lists that are to be merged.
*/
void merge_lists(struct Node* f, struct Node* s){
    // Declare a Node pointer 'last' to keep track of the last node in the merged list
    Node* last;
    // If the data in the first node of the first linked list is less than the data in the first node of the second linked list,
    // assign the first node of the first linked list to 'last' and 'third' and set the 'next' pointer of 'last' to null.
    if(f->data < s->data){
        last = third = f;
        f = f->next; // Move the first node of the first linked list to the second node
        last->next = nullptr; // Set the 'next' pointer of the last node to null
        f = f->next;
        last->next = nullptr;
    } 
    // If the data in the first node of the second linked list is less than or equal to the data in the first node of the first linked list,
    // assign the first node of the second linked list to 'last' and 'third' and set the 'next' pointer of 'last' to null.
    else{
        last = third = s;
        s = s->next; // Move the first node of the second linked list to the second node
        last->next = nullptr; // Set the 'next' pointer of the last node to null
        s = s->next;
        last->next = nullptr;
    }

    // Loop as long as both 'f' and 's' are not null
    while(f != nullptr && s != nullptr){
        // If the data in the first node of the first linked list is less than the data in the first node of the second linked list,
        // assign the first node of the first linked list to the 'next' pointer of 'last', assign 'f' to 'last', move the first node of the first linked list to the second node and set the 'next' pointer of 'last' to null.
        if(f->data < s->data){
            last->next = f;
            last = f;
            f = f->next;
            last->next = nullptr;
        }   
        // If the data in the first node of the second linked list is less than or equal to the data in the first node of the first linked list,
        // assign the first node of the second linked list to the 'next' pointer of 'last', assign 's' to 'last', move the first node of the second linked list to the second node and set the 'next' pointer of 'last' to null.
        else{
            last->next = s;
            last = s;
            s = s->next;
            last->next = nullptr;
        }
    }
    // If 'f' is not null, assign the remaining nodes of the first linked list to the 'next' pointer of 'last' starting from the second node.
    if(f != nullptr){
        last->next = f;
        f = f->next;
    }
    // If 's' is not null, assign the remaining nodes of the second linked list to the 'next' pointer of 'last' starting from the second node.
    if(s != nullptr){
        last->next = s;
        s = s->next;
    }
}

int main(){
    int A[] = {22,4,8,9,10};
    int B[] = {4,12,14,24};

    create_node1(A,5);
    create_node2(B,4);
    merge_lists(first, second);
    display(third);
    return 0;
}