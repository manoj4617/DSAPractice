#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node *left, *right;
		node(int val)
		: data(val),
		  left(NULL),
		  right(NULL)	
		{	
		}

    node* recurssive_search_bst(node* p, int key){

        if(p == nullptr){
            return NULL;
        }
        if(p->data == key){
            return p;
        }

        else {
            if(p->data > key){
                return recurssive_search_bst(p->left, key);
            }
            else{
                return recurssive_search_bst(p->right, key);
            }
        }
    }

    node* itr_search_bst(node *p , int key){
        if(!p)
            return NULL;
        while(p){
            if(p->data == key)
                return p;
            if(p->data > key)
                p = p->left;
            else
                p = p->right;
        }	
        return NULL;
    }

    void insert_in_bst(node *p, int val){
        node *prev;
        node *r = new node(val);

        if(!p){
            p = r;
            return;		
        }
        while(p){
            prev = p;
            if(p->data == val)
                return;
            else{
                if(p->data > val)
                    p = p->left;
                else
                    p = p->right;
            }
        }

        if(prev->data > val)
            prev->left = r;
        else
            prev->right = r;
    }

    node* recurssive_insert(node *p, int val){
        node *r; 
        if(p == nullptr){
            r = new node(val);
            return r;
        }

        if(p->data > val)
            p->left = recurssive_insert(p->left, val);
        else
            p->right = recurssive_insert(p->right, val);
        return r;
    }

    void inorder(node *p){
        if(p){
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }
};

int main(){
    node *p = nullptr,*t;
    p = t->recurssive_insert(p,10); 
    t->recurssive_insert(p,2);
    t->recurssive_insert(p,13); 
    t->recurssive_insert(p,5); 
    t->recurssive_insert(p,3); 
    t->recurssive_insert(p,9);     
    t->inorder(p);
    return 0;
}