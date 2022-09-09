#include<iostream>
#include<algorithm>

using namespace std;

void array_rearrange(int *a, int n){
    int arr[n],i=0,k=0,l=n-1;
    while(i < n){
        arr[i] = *a + k;
        arr[++i] = *a + l;

        k++;
        l--;
    }
}

int main(){

    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a,a+n);
    array_rearrange(a,n);
    for(int i=0;i<n;++i){
        cout << *a + i <<" ";
    }

    return 0;
}