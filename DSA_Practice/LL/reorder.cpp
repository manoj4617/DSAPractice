#include "ll_inserting_last.h"
#include <cstddef>

Node* reorder(Node* head){
    //find middle node
    int count = 0;
    Node* temp = nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //reverse second half
    Node* cur = slow;
    Node* nxt = nullptr;
    Node* prv = nullptr;
    while(cur != nullptr){
        cur->next = prv;
        prv = cur;
        cur = nxt;
        if(nxt != nullptr)
            nxt = nxt->next;
    }
    temp->next = prv;

    //merge first and second half
    Node* merger = temp->next;
    temp = head;
    while(merger->next != nullptr){
        Node* temp2 = temp->next;
        temp->next = merger;
        temp = temp2;
        temp2 = merger->next;
        temp->next->next = temp;
        temp = temp2;
    }

    return head;
}

int main(){
    insert_last(1);
    insert_last(3);
    insert_last(4);
    insert_last(5);
    insert_last(7);
    insert_last(9);
    insert_last(8);
    insert_last(10);
    display(head);
    reorder(head);
    cout << "\n";
    display(head);


    return 0;
}