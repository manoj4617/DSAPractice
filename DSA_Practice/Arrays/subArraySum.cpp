#include<iostream>
#include<vector>

using namespace std;

void subArray(int arr[], int n, int s){
    int sum,j,i;
    for(i=0;i<n;++i){
        sum = arr[i];
        for(j=i+1;j<=n;++j){
            if(sum == s){
                cout<<i << " "<<j-1;
                return;
            }
            if(sum > s || j == n)
                break;
            sum += arr[j];   
        }
    }
}

int main(){
    int n;
    long long s;
    cin >> n >> s;
    int arr[n];

    for(int i=0;i<n;++i){
        cin >> arr[n];
    }

    subArray(arr,n,s);
}