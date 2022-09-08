#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    string str;
    int x,H = 0;
    cin >> str;
    
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for(int i=0;i<str.length();++i){
        x = 1;
        x = x << ((int)str[i] - 97); 

        if((x & H) > 0){    // Mask and check for duplicate bits
            cout << str[i];
        }else{
            H = H | x;      // Merge to set the bit 
        }
    }

    return 0;
}