#include "ll_inserting_last.h"

// Function to reverse every k-group of nodes in a linked list.
// The function takes in a pointer to the head of the linked list and an integer k.
// It returns a pointer to the head of the updated linked list.
Node* reverse_k_group(Node* head, int k){
    // Create a dummy node to act as a placeholder for the actual head of the list.
    Node* dummy = new Node;
    dummy->next = head;

    // Pointer to track the current position in the linked list.
    Node* ptr = dummy;
    // Pointer to track the end of the current k-group.
    Node* tracker = nullptr;
    // Pointer to track the nodes in the current k-group.
    Node* current = nullptr;
    // Pointer to track the previous node in the current k-group.
    Node* prev = nullptr;
    // Pointer to track the next node after the current k-group.
    Node* next = nullptr;

    // Loop until we reach the end of the linked list.
    while(ptr != nullptr){
        // Update the tracker pointer to the end of the current k-group.
        tracker = ptr;
        // Loop k times to find the end of the current k-group.
        for(int i=0;i<k;i++){
            // If we reach the end of the linked list, break out of the loop.
            if(tracker == nullptr )
                break;
            // Move the tracker pointer to the next node.
            tracker = tracker->next;
        }
        // If we reach the end of the linked list, break out of the loop.
        if(tracker == nullptr)
            break;
        // Update the current pointer to the start of the current k-group.
        current = ptr->next;
        // Loop k times to reverse the nodes in the current k-group.
        for(int i=0;i<k;++i){
            // Store the next pointer of the current node.
            next = current->next;
            // Update the next pointer of the current node to point to the previous node.
            current->next = prev;
            // Update the previous pointer to the current node.
            prev = current;
            // Move the current pointer to the next node.
            current = next;
        }
        // Store the next pointer of the current k-group.
        Node* temp = ptr->next;
        // Update the next pointer of the current k-group to point to the node after the current k-group.
        temp->next = current;
        // Update the next pointer of the previous k-group to point to the reversed k-group.
        ptr->next = prev;
        // Move the pointer to the next k-group.
        ptr = temp;
    }

    // Store the head of the updated linked list.
    head = dummy->next;
    // Delete the dummy node since we no longer need it.
    delete dummy;
    // Return the head of the updated linked list.
    return head;
}


int main(){

    int k;
    cin >> k;

    insert_last(10);
    insert_last(11);
    insert_last(12);
    insert_last(13);
    insert_last(14);
    insert_last(15);
    insert_last(16);

    display(head);
    cout << endl;

    head = reverse_k_group(head, k);

    display(head);
    return 0;
}