#include <iostream>
#include "ll_inserting_last.h"

Node* RemoveLastNthElement(Node* head, int n) {
    // If the linked list is empty, return nullptr as there is nothing to remove.
    if (head == nullptr)
        return nullptr;

    // Create a dummy node to handle edge cases such as removing the head node.
    Node* dummy = new Node;
    dummy->next = head;

    // Initialize two pointers. 'right' is used to find the n-th node from the end.
    // 'left' is used to track the node before the one we want to remove.
    Node *right = head;
    Node *left = dummy;

    // Move the 'right' pointer n steps ahead.
    while (n > 0) {
        right = right->next;
        n--;
    }

    // Move both 'right' and 'left' pointers one step at a time until 'right' reaches the end.
    // 'left' will then be pointing to the node just before the target node.
    while (right != nullptr) {
        left = left->next;
        right = right->next;
    }

    // Remove the n-th node from the end by changing the next pointer of the 'left' node.
    left->next = left->next->next;

    // Return the head of the modified list. The dummy node's next points to the actual head.
    return dummy->next;
}



int main(){

    insert_last(1);
    insert_last(2);
    insert_last(3);
    insert_last(4);
    insert_last(5);
    insert_last(5);
    // insert_last(15);
    // insert_last(25);

    display(head);
    cout << endl;

    RemoveLastNthElement(head, 6);

    display(head);

    return 0;
}