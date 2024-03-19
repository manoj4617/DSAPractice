#include <iostream>
#include "ll_inserting_last.h"

Node* RemoveLastNthElement(Node* head, int n){
    if(head == nullptr)
        return nullptr;

    Node *right = head;
    Node *left = head;

    int i=0;
    while(i <= n){
        if(right == nullptr){
            head = head->next;
            return head;     
        }

        right = right->next;
        i++;
    }

    while(right != nullptr){
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;
    return head;
}



int main(){

    insert_last(1);
    insert_last(2);
    // insert_last(3);
    // insert_last(4);
    // insert_last(5);
    // insert_last(5);
    // insert_last(15);
    // insert_last(25);

    display(head);
    cout << endl;

    RemoveLastNthElement(head, 1);

    display(head);

    return 0;
}