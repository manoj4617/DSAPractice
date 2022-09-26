#include<iostream>
#include<vector>

using namespace std;

int dup_in_sorted(int A[], int n){
    int count = 0;
    
    int lastDup = INT_MIN;

    for(int i=0;i<(sizeof(A)/sizeof(A[0]))-1;++i){
        if(A[i] == A[i+1] && A[i] != lastDup){
            int j = i+1;
            while(A[i] == A[j]){
                A[i] = A[j];
                j++;
                count++;
            }
            
            lastDup = A[i];
            i = j - 1;
        }
    }

    return count;
}

int main(){
    int n, temp;
    cin >> n;
    int num[n];

    for(int i=0;i<n;++i){
        cin >> num[i];
    }

    cout << dup_in_sorted(num, n) << endl;

    return 0;
}   