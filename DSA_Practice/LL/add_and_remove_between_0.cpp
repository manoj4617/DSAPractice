#include "ll_inserting_last.h"
#include <cstddef>
#include <iostream>

using namespace std;

void remove_between_zero(Node* head){
    Node* current = head;

    while(current){
        if(current->data == 0){
            int sum = 0;
            Node* temp = current->next;
            while(temp && temp->data != 0){
                sum += temp->data;
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            Node* node = new Node;
            node->data = sum;
            current->next = node;
            node->next = temp;
            // if(current->next != nullptr){
                // current->next->data = sum;
            // }

            current = current->next;
        }
        else{
            current = current->next;
        }
    }
}

int main(){
    insert_last(0);
    insert_last(2);
    insert_last(3);
    insert_last(4);
    insert_last(0);
    insert_last(4);
    insert_last(0);
    display(head);
    cout << endl;
    remove_between_zero(head);
    display(head);
    return 0;
}