#include <iostream>
#include "ll_inserting_last.h"

using namespace std;

/**
 * This function swaps every two adjacent nodes in a linked list. 
 * If the list has an odd number of nodes, the last node is unchanged.
 * @param head - Pointer to the head of the linked list.
 * @return - Pointer to the head of the updated linked list with swapped nodes.
 */
Node* swap_pairs(Node *head){
    // If the list is empty or has only one node, there is no swapping to be done.
    if(!head || head->next == nullptr)
        return head;

    // Create a dummy node to act as a placeholder for the actual head of the list.
    // This is necessary because we need to maintain the reference to the actual head node
    // so that we can return it at the end of the function.
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *p = dummy;

    // Iterate through the list while there are at least two nodes remaining.
    while(p->next && p->next->next){
        // first points to the first node in the pair of nodes to be swapped.
        Node *first = p->next;
        // second points to the second node in the pair of nodes to be swapped.
        Node *second = p->next->next;

        // Update the next pointer of the first node to point to the node
        // that was originally after the second node.
        first->next = second->next;
        // Update the next pointer of the second node to point to the first node.
        second->next = first;
        // Update the next pointer of the previous node (which is currently p)
        // to point to the second node.
        p->next = second;

        // Move p to the first node since we have just swapped the nodes
        // that p was pointing to.
        p = first;
    }

    // Store the new head of the list since the dummy node has been swapped
    // with the actual head node.
    Node *newHead = dummy->next;
    // Delete the dummy node since we no longer need it.
    delete dummy;
    // Return the new head of the updated linked list with swapped nodes.
    return newHead;
}

int main(){

    insert_last(1);
    insert_last(2);
    insert_last(3);
    insert_last(4);
    insert_last(5);

    display(head);
    swap_pairs(head);
    cout << "\n";
    display(head);
    return 0;
}