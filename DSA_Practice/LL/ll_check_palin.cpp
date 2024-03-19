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

bool is_palindrome(Node* head){
        Node* middle = head, *p = head;
        int l = 0;
        while(p){
            l++;
            p = p->next;
        }   

        for(int i=1;i<(l/2)+1;++i){
            middle = middle->next;
        }
        
        while(middle){
            if(head->data != middle->data)
                return false;
            else{
                middle = middle->next;
                head = head->next;
            }
        }
        return true;
}

int main(){
    int A[] = {2,3,5,5,3,2};
    create_node(A,5);    
    cout << is_palindrome(first);
    return 0;
}