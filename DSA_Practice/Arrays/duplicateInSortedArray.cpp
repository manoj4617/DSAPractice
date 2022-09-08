#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n, A[100],lastDup = 0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i];
    }

    sort(A,A+n);
    for(int i=0;i<n-1;++i){
        if(A[i] == A[i+1] && A[i] != lastDup){
            int j = i+1;
            while(A[i] == A[j]){
                j++;
            }
            cout<<"Repeated number "<<A[i]<<" repeated "<<(j-i)<<" times"<<endl;
            lastDup = A[i];
            i = j - 1;
        }
    }

    return 0;
}