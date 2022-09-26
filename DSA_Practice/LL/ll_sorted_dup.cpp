#include<iostream>
#include "ll_inserting_last.h"

using namespace std;

void remove_dup(struct Node* list){
    Node* p = list;
    Node* q = p->next;

    while(q != nullptr){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main(){

    sorted_insert(head,12);
    sorted_insert(head,12);
    sorted_insert(head,13);
    sorted_insert(head,13);
    sorted_insert(head,15);
    sorted_insert(head,18);
    display(head);
    cout << endl;
    remove_dup(head);
    display(head);
    return 0;
}