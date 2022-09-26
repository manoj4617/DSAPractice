#include<iostream>
#include<string>

using namespace std;

string reduce(string s){
    bool flag = false;

    int i=0,j=s.length()-1;

    while(i < j){
        if(s[i] == s[i+1]){
            s.erase(i,2);
            j = j - 2;
            i = 0;
        }
        else{
            i++;
        }
    }
    if(s.length() == 0)
        return "Empty String";

    return s;
}

int main(){

    string s;
    getline(cin, s);
    cout << reduce(s) << endl;

    return 0;
}