#include<iostream>
#include<unordered_map>
#include<set>
#include<string>

using namespace std;

set<string> find_dna_seq(string str, int n){

    unordered_map<string,int> hash;
    set<string> res_set;
   
    string sub_str = "";
    int start = 0, end = n-1;

    while(end < str.length()){

        sub_str = str.substr(start, n);
        if(hash.find(sub_str) != hash.end()){
            hash[sub_str]++;
            if(hash[sub_str] >= 2)
                res_set.insert(sub_str);
        }
        else{
            hash[sub_str]++;
        }
        end++;
        start++;
    }

    return res_set;
}

int main(){

    string str;
    getline(cin, str);
    int n;
    cin >> n;

    set<string> res = find_dna_seq(str,n);

    for(set<string>::iterator it = res.begin(); it != res.end();++it){
        cout << *it << endl;
    }

    return 0;
}