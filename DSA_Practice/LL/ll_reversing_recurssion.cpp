#include<iostream>
#include "ll_inserting_last.h"

using namespace std;

/**
 * This function reverses a linked list recursively.
 * It takes two parameters:
 *   - q: A pointer to the current node.
 *   - p: A pointer to the next node.
 *
 * The function works by recursively calling itself with the next node as the current node.
 * As it recurses, it updates the next pointer of each node to form a reversed linked list.
 * Once the recursion is complete and the current node is the last node of the original list,
 * the function sets the head of the linked list to the current node.
 *
 * @param q A pointer to the current node.
 * @param p A pointer to the next node.
 */
void reverse_recurssion(struct Node* q, struct Node* p){
    
    // If the current node is not null, recursively call the function with the next node
    // as the current node, and update the next pointer of the current node to the previous current node.
    if(p != nullptr){
        reverse_recurssion(p , p->next);
        p->next = q;
    }
    // If the current node is null, it means we have reached the last node of the original list.
    // Update the head of the linked list to the current node to form the reversed linked list.
    else{
        head = q;
    }
}

int main(){
    insert_last(10);
    insert_last(4);
    insert_last(7);
    insert_last(9);
    insert_last(1);
    insert_last(5);
    display(head);
    cout << endl;

    reverse_recurssion(nullptr, head);
    display(head);
    return 0;
}