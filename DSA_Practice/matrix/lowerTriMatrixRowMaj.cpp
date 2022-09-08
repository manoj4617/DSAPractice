#include<iostream>

using namespace std;

class DiagonalMatrix{
    private:
        int *A;
        int n;
    public:
        DiagonalMatrix(){
            n = 2;
            A = new int[3];
        }
        DiagonalMatrix(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        ~DiagonalMatrix(){
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
};

void DiagonalMatrix :: Set(int i, int j, int x){
    if(i >= j)
        A[(i * (i - 1)/2) + (j-1)] = x;
}

int DiagonalMatrix :: Get(int i, int j){
    if( i >= j) 
        return A[(i * (i - 1)/2) + (j-1)];
    return 0;
}

void DiagonalMatrix :: Display(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i >= j){
                cout << A[(i * (i - 1)/2) + (j-1)] << " ";
            }
            else{
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
}


int main(){

    int n,val;
    cin >> n;
    DiagonalMatrix d{n};

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin >> val;
            d.Set(i,j,val);
        }
    }
    cout<<endl;
    d.Display(); 

    return 0;   
}