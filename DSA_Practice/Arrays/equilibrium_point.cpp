#include<iostream>

using namespace std;

int findEqui(long long a[], int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int rsum = 0, lsum = 0;
    
    for(int i=0;i<n/2;++i){
        lsum += a[i];
    }
    for(int j=n-1;j>n/2;--j){
        rsum += a[j];
    }
    int mid = n/2;
    int left = mid - 1;
    int right = mid + 1;
    while(left != 0 || right!= 0){
        if(lsum == rsum)
            return left+1; 
        else{
            if(lsum > rsum){
                lsum -= a[left];
                rsum += a[mid];
                mid = left;
                left--;
                right--;
            }
            else if(lsum < rsum){
                rsum -= a[right];
                lsum += a[mid];
                mid = right;
                right++;
                left++;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    long long a[n];

    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    cout << findEqui(a,n) << endl;
    return 0;
}