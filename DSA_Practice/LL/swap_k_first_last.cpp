#include "ll_inserting_last.h"

/**
 * This function swaps the k-th first node with the last node of a linked list.
 * It takes two parameters:
 *   - head: A pointer to the head of the linked list.
 *   - k: An integer representing the position of the first node to be swapped.
 *
 * The function works by traversing the linked list twice:
 *   - The first time, it finds the node at the k-th position and the last node of the list.
 *   - The second time, it swaps the nodes.
 *
 * @param head A pointer to the head of the linked list.
 * @param k An integer representing the position of the first node to be swapped.
 *
 * @return A pointer to the head of the updated linked list with the nodes swapped.
 */
Node* swap_nodes(Node* head, int k){
    // If the list is empty or the given positions are the same, there is no reversing to be done.
    if(!head){
        return head;
    }

    // Traverse the linked list to find the node at the k-th position and the last node.
    Node* cur = head; // Initialize a pointer to traverse the linked list.
    Node* prev_cur = nullptr; // Initialize a pointer to store the previous node in the linked list.
    int count = 0; // Initialize a counter to keep track of the number of nodes traversed.
    while(count  != k - 1){ // Traverse the linked list until the k-th position is reached.
        prev_cur = cur; // Update the previous node pointer to the current node.
        cur = cur->next; // Move the current node pointer to the next node.
        count++; // Increment the counter.
    }
    Node* front = cur; // Store the node at the k-th position in a variable.
    Node* end = head; // Initialize a pointer to traverse the linked list from the beginning.
    Node* prev_end = nullptr; // Initialize a pointer to store the previous node in the linked list.
    while(cur->next){ // Traverse the linked list until the end is reached.
        prev_end = end; // Update the previous node pointer to the current node.
        cur = cur->next; // Move the current node pointer to the next node.
        end = end->next; // Move the end node pointer to the next node.
    }

    // Swap the nodes.
    Node* temp = front->next; // Store the next pointer of the node at the k-th position.
    front->next = end->next; // Update the next pointer of the node at the k-th position to the next pointer of the last node.
    end->next = temp; // Update the next pointer of the last node to the next pointer of the node at the k-th position.
    if(prev_cur){ // If there is a previous node at the k-th position, update the next pointer of the previous node to the last node.
        prev_cur->next = end;
    }
    else{ // If there is no previous node at the k-th position, update the head of the linked list to the last node.
        head = end;
    }
    prev_end->next = front; // Update the next pointer of the previous node of the last node to the node at the k-th position.

    return head; // Return the updated linked list with the nodes swapped.
}


int main(){
    insert_last(10);
    insert_last(4);
    insert_last(7);
    insert_last(9);
    insert_last(1);
    insert_last(5);
    display(head);
    head = swap_nodes(head, 1);
    cout << "\n";
    display(head);
    return 0;
}