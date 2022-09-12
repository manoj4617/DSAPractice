#include<iostream>

using namespace std;

class Subsequence{
    public:
        bool is_subsequence(string s, string t){
            int k = 0;
            for(int i=0;i<t.length();++i){
                if(s[k] == t[i]){
                    k++;
                }
            }
            if(k < s.length()){
                return false;
            }
            else{
                return true;
            }
        }
};

int main(){
    Subsequence sub;

    string s,t;
    cin >> s >>t;
    cout << sub.is_subsequence(s,t) << endl;
    return 0;
}