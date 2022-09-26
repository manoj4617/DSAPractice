#include<iostream>
#include<vector>

using namespace std;

string longest_prefix(vector<string> str){

    string pre = str[0];

    for(int i=1;i<str.size();++i){
        if(pre.size()){
            for(int k=0;k<pre.size();++k){
                if(pre[k] != str[i][k]){
                    pre = pre.substr(0,k);
                    break;
                }
            }
        }
        else return "";
    }

    return pre;
}

int main(){

    vector<string> s;
    int n;
    cin >> n;
    string temp;

    for(int i=0;i<n;++i){
        cin >> temp;
        s.push_back(temp);
    }

    cout << longest_prefix(s) << endl;
    return 0;
}