#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = new Node;

void create(int a[], int n){
    Node *temp , *last;

    head->data = a[0];
    head->next = nullptr;
    last = head;

    for(int i=1;i<n;++i){
        temp = new Node;
        temp->data = a[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

/*
 * This function searches for a node with a given key in a linked list.
 * It takes two parameters:
 *   - p: A pointer to the current node.
 *   - key: The key value to search for.
 *
 * The function works by iterating through the linked list until it finds a node with the given key.
 * If a node with the given key is found and it is the first node in the list, it is returned.
 * If a node with the given key is found and it is not the first node in the list, it is moved to the front of the list.
 * If no node with the given key is found, the function returns nullptr.
 *
 * @param p A pointer to the current node.
 * @param key The key value to search for.
 * @return A pointer to the node with the given key if found, nullptr otherwise.
 */
Node* search(struct Node* p, int key){
    // Initialize a pointer to keep track of the previous node.
    Node *q;
    q = nullptr;

    // Iterate through the linked list until a node with the given key is found or the end of the list is reached.
    while(p!=nullptr){
        // If a node with the given key is found and it is the first node in the list, return it.
        if(p->data == key && q == nullptr){
            return p;
        }
        // If a node with the given key is found and it is not the first node in the list, move it to the front of the list.
        if(p->data == key){
            // Update the next pointer of the previous node to skip the current node.
            q->next = p->next;
            // Update the next pointer of the current node to point to the head of the list.
            p->next = head;
            // Update the head of the list to point to the current node.
            head = p;
            // Return the current node.
            return p;
        }
        // Update the previous node pointer to the current node.
        q = p;
        // Move to the next node in the list.
        p = p->next;
    }

    // If no node with the given key is found, return nullptr.
    return nullptr;
}

void display(struct Node *p){
    while(p!=nullptr){
        cout << p->data << "->" << flush;
        p = p->next;
    }
}


int main(){

    int a[] = {4,29,82,1,9,8,7,4};
    create(a,sizeof(a)/sizeof(a[0]));
    Node *p = head;
    cout<< "List before searching"<<endl;
    display(p);
    cout << endl;
    Node *res = search(p,7);
     res = search(p,82);
     res = search(p,8);

    cout << res->data<<endl;
    p = head;
    cout<< "List after searching"<<endl;
    display(p);
    return 0;
}