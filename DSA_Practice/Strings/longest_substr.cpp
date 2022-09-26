#include<iostream>
#include <unordered_map>

using namespace std;

int longest_substr(string s){
    unordered_map<char,bool> count;
    int start = 0,ans = 0;

    for(int end = 0;end<s.length();++end){
        if(count[s[end]]){
            ans = max(ans, end - start);
            start++;
        }else{
            count[s[end]] = true;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << longest_substr(s) << endl;
    return 0;
}