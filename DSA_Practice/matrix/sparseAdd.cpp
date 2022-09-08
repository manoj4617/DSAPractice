#include<iostream>
#include "sparseMatrix.h"

using namespace std;

void addSparseMatrix(struct SparseMatrix *s1, struct SparseMatrix *s2){

    struct SparseMatrix res;
    res.m = s1->m;
    res.n = s1->n;
    res.e = new Element[s1->num + s2->num];

    if(s1->m != s2->m || s2->n != s1->n){
        return;
    }

    int i=0,j=0,k=0;
    while(i < s1->num && j < s2->num){
        if(s1->e[i].row < s2->e[j].row)
            res.e[k++] = s1->e[i++];
        else if(s1->e[i].row > s2->e[j].row)
            res.e[k++] = s2->e[j++];
        else if(s1->e[i].col < s2->e[j].col)
            res.e[k++] = s1->e[i++];
        else if(s1->e[i].col > s2->e[j].col)
            res.e[k++] = s2->e[j++];
            else{
                res.e[k] = s1->e[i++];
                res.e[k++].element += s2->e[j++].element;
            }

    }

    display(res);
}

int main(){

    struct SparseMatrix s1;
    struct SparseMatrix s2;

    Create(&s1);
    Create(&s2);

    display(s1);
    display(s2);

    addSparseMatrix(&s1,&s2);
}