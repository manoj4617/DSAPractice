#include<iostream>
#include<algorithm>

using namespace std;

void array_rearrange(int a[], int n){
    long long m = a[n-1];
    m++;
    int back = n-1, front = 0;

    for(int i=0;i<n;++i){
        if(i%2 == 0){
            long long v = a[back--] % m;
            a[i] += m*v;
        }
        else{
            long long v = a[front++] % m;
            a[i] += m*v;
        }
    }

    for(int i=0;i<n;++i){
        cout << a[i] / m << " ";
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

    return 0;
}