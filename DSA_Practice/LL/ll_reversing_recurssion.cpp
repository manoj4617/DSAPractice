#include<iostream>
#include "ll_inserting_last.h"

using namespace std;

void reverse_recurssion(struct Node* q, struct Node* p){
    
    if(p != nullptr){
        reverse_recurssion(p , p->next);
        p->next = q;
    }
    else{
        head = q;
    }
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

    reverse_recurssion(nullptr, head);
    display(head);
    return 0;
}