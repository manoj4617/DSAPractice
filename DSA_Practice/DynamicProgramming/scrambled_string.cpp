#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> memo;

bool isScramble(string a, string b){
    //base condition
    if(a == b){
        return true;
    }

    if(a.size() != b.size())
        return false;
    if(a.size() <= 1)
        return false;

    int n = a.size();
    bool flag = false;
    string key = a + "_" + b;

    if(memo.find(key) != memo.end()){
        return memo[key];
    }

    for(int i=1;i<n;++i){
        //swapping
        bool cond1 = isScramble(a.substr(0,i), b.substr(n-i,i)) &&
                        isScramble(a.substr(n-i,i), b.substr(0,n-i));

        //no swapping
        bool cond2 = isScramble(a.substr(0,i), b.substr(0,i)) &&
                        isScramble(a.substr(i,n-i), b.substr(i,n-i));

        if(cond1 || cond2){
            flag = true;
            break;
        }
    }
    return memo[key] = flag;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()) cout << false;

    if(a.empty() || b.empty()) cout << false;

    cout << isScramble(a,b);
    return 0;

}