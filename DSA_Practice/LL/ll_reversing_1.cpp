#include<iostream>
#include "ll_inserting_last.h"

using namespace std;


/*
This function is used to reverse a linked list by manipulating pointers.

The algorithm works by iteratively traversing the list and swapping the
next pointers of consecutive nodes. It uses three pointers, p, q, and r, to
achieve this. The variable p is used to traverse the list, q is used to keep
track of the current node, and r is used to keep track of the previous node.

The while loop continues as long as p is not null (i.e., we haven't reached the
end of the list). Within the loop, the pointers are swapped and q and p are
advanced one step. The line q->next = r; updates the next pointer of the
current node to point to the previous node, effectively reversing the link.

After the loop ends, the head pointer is updated to point to the new head of
the list, which is now the last node of the original list.

Parameters:
    struct Node* list - the head pointer of the linked list to be reversed.

Returns:
    None
*/
void reverse_ll_link(struct Node* list){
    Node* p = head; // Pointer to traverse the list
    Node* q = nullptr; // Pointer to keep track of the current node
    Node* r = nullptr; // Pointer to keep track of the previous node

    while(p != nullptr){ // Traverse the list until the end is reached
        r = q; // Update the previous node pointer
        q = p; // Update the current node pointer
        p = p->next; // Advance the node pointer

        q->next = r; // Update the next pointer of the current node
    }
    head = q; // Update the head pointer to the new head of the list
}

int main(){
    insert_last(10);
    insert_last(4);
    insert_last(7);
    insert_last(9);
    insert_last(1);
    insert_last(5);
    insert_last(15);
    insert_last(25);

    display(head);
    cout << endl;

    reverse_ll_link(head);

    display(head);
    return 0;
}