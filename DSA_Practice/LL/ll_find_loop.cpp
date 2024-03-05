#include<iostream>
#include"ll_inserting_last.h"

using namespace std;
Node* first;
void create_node(int A[], int n){
    Node* t , *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for(int i=1;i<n;++i){
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void remove_loop(Node *loop_node, Node *head){

    Node *p = loop_node;
    Node *q = loop_node;

    if(p == q){
        p = head;

        if(p == q){
            while(q->next != p){
                q = q->next;
            }
        }
        else{
            while(p->next != q->next){
                p = p->next;
                q = q->next;
            }
        }

        q->next = NULL;
    }

}


bool is_loop_present(struct Node* f){
    Node* q, *p;
    p = q = f;
    do{
        p = p->next;                            //Move p by 1 step
        q = q->next;                            //p and q will meet at some node if there is a loop 
        q = q != nullptr ? q->next : nullptr;   //Move  q by 2 steps
    }while(p && q && p!=q);

    remove_loop(p,f);

    return p == q ? true : false; 
}


int main(){
    int A[] = {10};
    create_node(A,5);
    Node *t1,*t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;
    cout << is_loop_present(first);
    return 0;
}