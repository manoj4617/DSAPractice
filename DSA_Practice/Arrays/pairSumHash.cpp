#include<iostream>

using namespace std;

int findLargest(int a[] , int n){
    int big = a[0];
    for(int i=0;i<n;++i){
        if(big < a[i]){
            big = a[i];
        }
    }
    return big;
}

int main(){

    int n,k;
    cin>>n;
    cin>>k;
    int A[n];

    for(int i=0;i<n;++i){
        cin>>A[i];
    }

    int h = findLargest(A,n);
    int hash[h] = {0};

    for(int i=0;i<n;++i){
        if(hash[k - A[i]] != 0 && k - A[i] > 0){
            cout<<"("<<A[i]<<","<<k-A[i]<<")"<<endl;
        }
        hash[A[i]]++;
    }

  

    return 0;
}