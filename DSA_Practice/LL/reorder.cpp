#include "ll_inserting_last.h"

// This function reorders a linked list by reversing the second half of the list and
// then merging the two halves together.
// It takes a pointer to the head of the linked list as a parameter and returns a pointer
// to the head of the updated linked list.
Node* reorder(Node* head){
    // Find the middle node of the linked list.
    if(!head) // If the linked list is empty, return the head.
        return head;

    Node* slow = head; // Initialize two pointers, slow and fast, to traverse the linked list.
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){ // Traverse the linked list until the fast pointer reaches the end or the next-to-end node.
        slow = slow->next; // Move the slow pointer to the next node.
        fast = fast->next->next; // Move the fast pointer to the node after the next node.
    }
    
    // Reverse the second half of the linked list.
    Node* cur = slow; // Initialize three pointers, cur, nxt, and prv, to traverse and reverse the second half of the linked list.
    Node* nxt = nullptr;
    Node* prv = nullptr;
    while(cur != nullptr){ // Traverse the second half of the linked list.
        nxt = cur->next; // Store the next pointer of the current node.
        cur->next = prv; // Update the next pointer of the current node to point to the previous node.
        prv = cur; // Update the previous pointer to the current node.
        cur = nxt; // Move the current pointer to the next node.
    }
    Node* first = head; // Store the head of the linked list in two separate variables for easier manipulation.
    Node* second = prv;

    // Merge the two halves of the linked list.
    while(second->next != nullptr){ // Traverse the merged linked list until the end is reached.
        Node* temp2 = first->next; // Store the next pointer of the first node.
        first->next = second; // Update the next pointer of the first node to point to the second node.
        first = temp2; // Move the first pointer to the next node.
        temp2 = second->next; // Store the next pointer of the second node.
        second->next = first; // Update the next pointer of the second node to point to the first node.
        second = temp2; // Move the second pointer to the next node.
    }

    return head; // Return the head of the updated linked list.
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