#include<iostream>

using namespace std;

int main(){

    int num[] = {3,7,4,9,12,6,1,11,2,10};
    int n = sizeof(num)/sizeof(num[0]);
    int hash[13] = {0};


    //Time complexity is constant
    for(int i=0;i<n;++i){
        hash[num[i]]++;
    }
    for(int i = 1;i<13;++i){
        if(hash[i] == 0){
            cout<<"Missing number"<<i<<endl;
        }
    }

    return 0;
}