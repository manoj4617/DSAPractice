#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n,k, A[100],i,j;
    cin >> n;
    cin >> k;

    for(i=0;i<n;++i){
        cin >> A[i];
    }

    sort(A,A+n);
    
    i = 0,j = n-1;
    while(i != j){
        if(A[i] + A[j] > k){
            j--;
        }
        if(A[i] + A[j] < k){
            i++;
        }

        if(A[i] + A[j] == k){
            cout<<"("<<A[i]<<","<<A[j]<<")"<<endl;
            i++;
            j--;
        }
    }

    return 0;
}