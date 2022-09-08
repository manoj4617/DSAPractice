#include<iostream>

using namespace std;

int main(){

    int num[] = {6,7,8,9,11,12,15,16,17,18,19};
    int n = sizeof(num)/sizeof(num[0]);
    int diff = num[0] - 0;

    //Time complexity O(n)
    for(int i=0;i<n;++i){
        if(num[i] - i != diff){
            while(diff < num[i] - i){
                cout<<"Missing number"<<diff + i<<endl;
                diff++;
            }
        }
    }



    return 0;
}