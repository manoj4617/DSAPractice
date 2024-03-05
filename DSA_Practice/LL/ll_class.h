#include<iostream>

class Node{
    public: 
        int data;
        Node* next;
};

class LinkedList{
    private:
        Node* first;
    public:
        LinkedList(){first=nullptr;}
        LinkedList(int A[], int n){
            Node* last, *t;
            first = new Node();
            first->data = A[0];
            first->next = nullptr;

            for(int i=1;i<n;++i){
                t = new Node();
                t->data = A[i];
                t->next = nullptr;
                last->next = t;
                last = t;
            }
        }
        ~LinkedList(){
            Node* p = first;
            while(first){
                first = first->next;
                delete p;
                p = first;
            }
        }
        void Display(){
            Node* p = first;
            while(p){
                std::cout << p->data << "->";
                p=p->next;
            }
            std::cout << std::endl;
        }
        void Insert(int idx, int x){
            Node *t , *p = first;

            if(idx < 0 || idx > Length())
                return;
            t = new Node();
            t->data = x;
            t->next = nullptr;

            if(idx == 0){
                first = t;
            }
            else{
                for(int i=0;i<idx-1;++i)
                    p = p->next;
                t->next = p->next;
                p->next = t;
            }
        }
        int Delete(int idx){
            Node *p = first, *q = nullptr;
            int x = -1;
            if(idx < 0 || idx > Length())
                return;
            
            if(idx == 0){
                first = first->next;
                x = p->data;
                delete p;
            }
            else{
                for(int i=0;i<idx-1;++i){
                    q = p;
                    p = p->next;
                }

                q->next = p->next;
                x = p->data;
                delete p;
            }
            return x;
        }
        int Length(){
            int count = 0;
            Node* p = first;
            while(p){
                count++;
                p=p->next;
            }
        }
};