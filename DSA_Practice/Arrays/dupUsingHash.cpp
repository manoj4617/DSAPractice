#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n,A[1000];
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    sort(A,A+n);
    int h = A[n];
    int l = A[0];

    int hash[h] = {0};

    for(int i = 0; i < n;++i){
        hash[A[i]]++;
    }

    for(int i = 1;i<h;++i){
        if(hash[i] > 1){
            cout<<"Repeated number "<<i<<" repeated "<<hash[i]<<" times"<<endl;
        }
    }
    return 0;
}