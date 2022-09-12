#include<iostream>
#include "ll_inserting_last.h"

using namespace std;

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

int main(){
    // insert_last(10);
    // insert_last(11);
    // insert_last(12);
    // insert_last(14);
    // insert_last(18);
    cout<< "before inserting" << endl;
    //display(head);

    sorted_insert(head,9);
    sorted_insert(head,17);
    sorted_insert(head,10);


    cout << "after inserting" << endl;
    display(head);
    return 0;
}