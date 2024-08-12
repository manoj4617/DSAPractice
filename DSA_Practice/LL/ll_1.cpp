#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
Node* head = new Node;

void create(int a[], int n){
    struct Node *t, *last;
    head->data = a[0];
    head->next = nullptr;
    last = head;

    for(int i=1;i<n;++i){
        t = new Node;
        t->data = a[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=nullptr){
        cout << p->data << "->" << flush;
        p = p->next;
    }
}

void displayRecurssive(struct Node *p){
    if(p != nullptr){
        //displayRecurssive(p->next); for reverse printing
        cout << p->data << "->" << flush;
        displayRecurssive(p->next);
    }
}

int findMax(struct Node* p){
    int max = INT_MIN;

    while(p){
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int findMaxRecurssive(struct Node* p){
    int x = 0;

    if(p == 0)
        return INT_MIN;
    
    x = findMaxRecurssive(p->next);
    return x > p->data ? x : p->data;
}

int main(){
    int a[] = {4,29,82,1,9,8,7,4};
    create(a,sizeof(a)/sizeof(a[0]));
    Node *p = head;
    displayRecurssive(p);
    cout << endl;
    cout << "Max number in list " << findMaxRecurssive(p) << endl;
    return 0;
}