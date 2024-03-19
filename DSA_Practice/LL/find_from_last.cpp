#include<iostream>
#include "ll_inserting_last.h"

using namespace std;

int return_from_last(Node* head, int n){
    if(!head)
        return -1;
    
    int count = 0;

    Node* p = head;

    while(head){
        count++;
        head = head->next;
    }

    int curr = 1;
    while(curr < count - n + 1){
        p = p->next;
        curr++;
    }

    return p->data;
}

int main(){

    int n;
    cin >> n;
    insert_last(2);
    insert_last(4);
    insert_last(12);
    insert_last(9);
    insert_last(8);
    insert_last(4);
    insert_last(1);
    cout << return_from_last(head, n);
    return 0;
}