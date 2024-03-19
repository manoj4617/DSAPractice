#include <iostream>
#include "ll_inserting_last.h"
#include <unordered_map>

using namespace std;


/**
 * Removes duplicate nodes from a linked list.
 * 
 * @param head Pointer to the head node of the linked list.
 * 
 * @return Pointer to the head node of the updated linked list without duplicates.
 * 
 * This function uses an unordered_map to keep track of duplicate nodes.
 * 
 * First, it iterates through the list, incrementing the count for each node value in the map.
 * This has an overall time complexity of O(N) where N is the number of nodes in the linked list.
 * Space complexity is O(N) due to the map.
 * 
 * After the first iteration, the map will contain an entry for each node value in the list,
 * with the count of how many times that node value appears in the list.
 * 
 * The function then iterates again, skipping over nodes whose count in the map is greater than 1.
 * Nodes with a count of 1 are kept.
 * 
 * The function keeps a pointer to the previous node (p) and a pointer to the current node (q).
 * The function starts by setting p to a dummy node with data set to 0, and setting q to head.
 * The dummy node is used as a placeholder for the actual head of the list.
 * 
 * The function goes through each node in the list, starting with the head (q).
 * If the count in the map for the current node (q->data) is greater than 1, 
 * then the function knows that there are duplicate nodes with that value in the list.
 * 
 * The function then deletes all subsequent duplicate nodes by repeatedly setting temp to q, 
 * setting q to q->next, and setting p->next to q.
 * This effectively removes the node pointed to by temp from the list.
 * The function continues this process until q is at the end of the list or until the count for
 * the current node (q->data) is 1, at which point the function sets p to q and moves on to the next node.
 * 
 * The function continues iterating until it reaches the end of the list.
 * 
 * After the second iteration, the function returns the dummy node's next pointer,
 * which points to the head of the updated linked list without any duplicate nodes.
 */
Node *removeDup(Node *head)
{

    if (!head)
    {
        return nullptr;
    }
    unordered_map<int, int> rep;

    Node *t = head;
    while (t)
    {
        rep[t->data]++;
        t = t->next;
    }

    Node *dummy = new Node(0);
    dummy->next = head;
    Node *p = dummy;
    Node *q = head;

    while (q)
    {
        if (rep[q->data] > 1)
        {
            while (q && rep[q->data] > 1)
            {
                Node *temp = q;
                q = q->next;
                p->next = q;
                delete temp;
            }
        }
        else
        {
            p = q;
            q = q->next;
        }
    }

    return dummy->next;
}


int main(){

    // insert_last(1);
    // insert_last(2);
    // insert_last(3);
    // insert_last(3);
    // insert_last(4);
    // insert_last(4);
    // insert_last(5);

    insert_last(-3);
    insert_last(-1);
    insert_last(-1);
    insert_last(0);
    insert_last(0);
    insert_last(0);
    insert_last(0);
    insert_last(0);
    insert_last(2);


    display(head);
    removeDup(head);
    cout << "\n";
    display(head);
    return 0;
}