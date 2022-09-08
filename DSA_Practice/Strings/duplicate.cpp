#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    string str;
    int hash[26] = {0};
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for(int i=0;i<str.length();++i){
        hash[(int)str[i] - 97] += 1;
    }

    for(int i=0;i<26;++i){
        if(hash[i] > 1){
            cout << char(i + 97) <<" "<< hash[i] << " times" << endl;
        }
    }

    return 0;
}