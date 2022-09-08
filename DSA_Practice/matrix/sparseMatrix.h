#include <iostream>

using namespace std;

struct Element{
    int row;
    int col;
    int element;
};

struct SparseMatrix{
    int m;
    int n;
    int num;
    struct Element *e;
};
 
void Create(struct SparseMatrix *s){
    cin >> s->m >> s->n;
    cin >> s->num;
    s->e = new Element[s->num];

    for(int i=0;i<s->num;++i){
        cin >> s->e[i].row >> s->e[i].col >> s->e[i].element;
    }
}

void display(struct SparseMatrix s){
    int k=0;
    for(int i=0;i<s.m;++i){
        for(int j=0;j<s.n;++j){
            if(i == s.e[k].row && j == s.e[k].col){
                cout << s.e[k++].element << " ";
            }
            else{
                cout << 0 <<" ";
            }
        }
        cout << endl;
    }
}

// int main(){

//     struct SparseMatrix s;
//     Create(&s);
//     display(s);

//     return 0;
// }