#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;++i){
        cin>>A[i];
    }

    int min = A[0], max = A[0];

    for(int i=0;i<n;++i){
        if(A[i] < min){
            min = A[i];
        }
        if(A[i] > max){
            max = A[i];
        }
    }

    cout<<"Max = "<<max<<endl;
    cout<<"Min = "<<min<<endl;


    return 0;
}