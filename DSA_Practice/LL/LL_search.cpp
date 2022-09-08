#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* head = new Node;

void create(int a[], int n){
    Node *temp, *last;

    head->data = a[0];
    head->next = nullptr;
    last->next = head;
    last = head;

    for(int i=1;i<n;++i){
        temp = new Node;
        temp->data = a[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

Node* search(struct Node *p, int key){
    while(p != nullptr){
        if(key == p->data){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

int main(){

    int a[] = {4,29,82,1,9,8,7,4};
    create(a,sizeof(a)/sizeof(a[0]));
    Node *p = head;
    Node *res = search(p,9);
    cout << res->data<<endl;
    return 0;
}