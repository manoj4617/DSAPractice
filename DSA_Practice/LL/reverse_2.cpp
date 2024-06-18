#include "ll_inserting_last.h"
/**
 * This function reverses a portion of a linked list between two given positions.
 * It takes three parameters:
 *   - head: A pointer to the head of the linked list.
 *   - left: The position of the first node to be reversed.
 *   - right: The position of the last node to be reversed.
 *
 * The function works by creating a dummy node to act as a placeholder for the actual head of the list.
 * It then iterates to the node before the left position and sets this node as the current node.
 * The function then iterates from the current node to the right position, reversing the nodes in the process.
 * Once all the nodes have been reversed, the function updates the head of the linked list and returns it.
 *
 * @param head A pointer to the head of the linked list.
 * @param left The position of the first node to be reversed.
 * @param right The position of the last node to be reversed.
 *
 * @return A pointer to the head of the updated linked list with the nodes reversed between the given positions.
 */
Node* reverse_between(Node* head, int left, int right) {
    // If the list is empty or the given positions are the same, there is no reversing to be done.
    if(!head || left == right){
        return head;
    }

    // Create a dummy node to act as a placeholder for the actual head of the list.
    Node* dummy = new Node;
    dummy->next = head;
    Node* prv = dummy;

    // Iterate to the node before the left position and set this node as the current node.
    for(int i=0;i<left-1;++i){
        prv = prv->next;
    }

    // Set the current node to the node at the left position.
    Node* cur = prv->next;

    // Iterate from the current node to the right position, reversing the nodes in the process.
    for(int i=0;i<right - left;++i){
        // Store the next node of the current node.
        Node* nxt  = cur->next;
        // Update the next pointer of the current node to point to the node after the current node.
        cur->next = nxt->next;
        // Update the next pointer of the next node to point to the previous node.
        nxt->next = prv->next;
        // Update the next pointer of the previous node to point to the next node.
        prv->next = nxt;
    }

    // Update the head of the linked list and return it.
    return dummy->next;
}


int main(){
    int left, right;
    cin >> left >> right;
    insert_last(10);
    insert_last(4);
    insert_last(7);
    insert_last(9);
    insert_last(1);
    insert_last(5);
    display(head);
    head = reverse_between(head, left, right);
    cout << "\n";
    display(head);
    cout << endl;
    return 0;
}
