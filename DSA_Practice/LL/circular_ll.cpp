#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void create_ll(int a[], int n){
    Node *last,*t;
    head = new Node;
    head->data = a[0];
    head->next = head;
    last = head;

    for(int i=1;i<n;++i){
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    do{
        cout << p->data <<"->";
        p = p->next;
    }while(p != head);
}

//recurssive display
void display_rr(struct Node *p){
    static int flag = 0;
    if(p != head || flag == 0){
        flag = 1;
        cout << p->data <<"->";
        display_rr(p->next);
    }
    flag = 0;
}
int Length(struct Node *p){
    int l = 0;
    do{
        l++;
        p = p->next;
    }while(p != head);
    return l;
}
void insert(struct Node *p , int pos, int val){
    Node *t = new Node;
    if(pos < 0 || pos > Length(p)){
        return;
    }
    if(pos == 0){
        t->data = val;
        if(head == nullptr){
            head = t;
            head->next = head; 
        }
        else{
            while(p->next != head)  
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        for(int i =0;i<pos-1;++i){
            p = p->next;
        }
        Node *t = new Node;
        t->data = val;
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    int a[] = {2,3,4,5,6,1};
    create_ll(a,6);
    display(head);
    cout << endl;
    insert(head,6,10);
    display(head);
    return 0;
}