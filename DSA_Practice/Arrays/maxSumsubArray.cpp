#include<iostream>

using namespace std;

int main(){
    int n,arr[1000],max = -999,subarraysum = 0;
    cin >> n;

    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    int maxNum = arr[0];
    for(int i=0;i<n;++i){
        subarraysum += arr[i];
        if(max < subarraysum){
            max = subarraysum;
        }
        if(subarraysum < 0){
            subarraysum = 0;
        }
    }

    cout<<max;

    return 0;
}