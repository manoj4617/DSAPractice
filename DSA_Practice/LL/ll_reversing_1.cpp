#include<iostream>
#include "ll_inserting_last.h"

using namespace std;

void reverse_ll_link(struct Node* list){
    Node* p = head;
    Node* q = nullptr;
    Node* r = nullptr;

    while(p != nullptr){
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }
    head = q;
}

int main(){
    insert_last(10);
    insert_last(4);
    insert_last(7);
    insert_last(9);
    insert_last(1);
    insert_last(5);
    display(head);
    cout << endl;

    reverse_ll_link(head);

    display(head);
    return 0;
}