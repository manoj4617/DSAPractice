#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = new Node;

void create(int a[] , int n){
    Node* t, *last;
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

int count(struct Node* p){
    int count_num=0;
    while(p->next != nullptr){
        count_num++;
        p = p->next;
    }
    return count_num;
}

void insert(struct Node* p, int pos, int val){
    Node* t = new Node;
    if(pos < 0 && pos > count(p)){
        return;
    }
    
    if(pos == 0){
        t->data = val;
        t->next = head;
        head = t;
    }
    else{
        for(int i=0;i<pos-1 && p;++i){
            p = p->next;
        }

        t->data = val;
        t->next = p->next;
        p->next = t;
    }
}

void display(struct Node* p){
    while(p->next != nullptr){
        cout << p->data << "->" << flush;
        p = p->next;
    }
}

int main(){
    int a[] = {3};
    create(a,sizeof(a)/sizeof(a[0]));
    cout << "before inserting" << endl;
    display(head);
    insert(head,0,50);


    cout<<endl;
    cout << "after inserting" << endl;
    display(head);
    return 0;
}