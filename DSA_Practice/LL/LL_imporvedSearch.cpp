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

Node* search(struct Node* p, int key){
    Node *q;
    q = nullptr;

    while(p!=nullptr){
        if(p->data == key && q == nullptr){
            return p;
        }
        if(p->data == key){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }

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