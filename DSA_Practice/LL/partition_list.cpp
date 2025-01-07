#include <cstddef>
#include <iostream>
#include "ll_inserting_last.h"


using namespace std;

Node* partitionList(Node* head, int val) {
    // Create two dummy nodes to act as the heads of the 'before' and 'after' lists
    Node* before_head = new Node(0);
    Node* after_head = new Node(0);

    // Initialize two pointers to track the last nodes of the 'before' and 'after' lists
    Node* before = before_head;
    Node* after = after_head;

    // Traverse the original list
    while (head) {
        // If the current node's data is less than the given value, append it to the 'before' list
        if (head->data < val) {
            before->next = head;
            before = before->next;
        } 
        // Otherwise, append it to the 'after' list
        else {
            after->next = head;
            after = after->next;
        }
        // Move to the next node in the original list
        head = head->next;
    }

    // Terminate the 'after' list to avoid cycles
    after->next = nullptr;
    // Connect the 'before' list with the 'after' list
    before->next = after_head->next;
    // The first node of the 'before' list is a dummy, so return the next node
    return before_head->next;
}

int main(){
    insert_last(1);
    insert_last(4);
    insert_last(3);
    insert_last(2);
    insert_last(5);
    insert_last(2);
    display(head);
    cout << "\n";
    int x = 3;
    head = partitionList(head, x);
    display(head);

    return 0;
}
