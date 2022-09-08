#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int hash[26] = {0},i;
    string str_1, str_2;
    cin >> str_1 >> str_2;

    transform(str_1.begin(), str_1.end(), str_1.begin(), ::tolower);
    transform(str_2.begin(), str_2.end(), str_2.begin(), ::tolower);

    if(str_1.length() != str_2.length()){
        cout << "not anagram";
        return 1;
    }

    for( i =0;i<str_1.length();++i){
        hash[(int)str_1[i] - 97] += 1;
    }

    for( i=0;i<str_1.length();++i){
        if(hash[(int)str_2[i] - 97] - 1 < 0){
            cout << "not anagram";
            break;
        }
        else{
            hash[(int)str_2[i] - 97] -= 1;
        }
    }

    if(str_2.length() == i){
        cout << "Anagram"<<endl;
    }
    return 0;
}