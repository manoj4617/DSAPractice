#include<iostream>
#include<vector>
using namespace std;

  


int main(){

    int arr[] = {1,2,3,4,9};
    int *p = arr;

   for(int i=0;i<5;++i){
    cout<<*p+i<<" ";
   }

    return 0;
}
    