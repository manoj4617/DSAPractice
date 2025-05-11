#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


bool isValid(string& s){
    int count = 0;
    for(char c : s){
        if(c == '('){
            count++;
        } else if(c == ')'){
            count--;
            if(count < 0){
                return false;
            }
        }
    }
    return count == 0;
}

void dfs(string& s, int start, int lremove, int rremove, unordered_set<string>& res){
    if(lremove == 0 && rremove == 0){
        if(isValid(s)){
            res.insert(s);
        }
        return;
    }

    for(int i=start; i < s.length(); i++){
        if(i != start && s[i] == s[i-1]){
            continue;
        }
        if(s[i] != '(' && s[i] != ')'){
            continue;
        }

        string cur = s.substr(0,i) + s.substr(i + 1);
        if(s[i] == '(' && lremove > 0){
            dfs(cur, i, lremove - 1, rremove, res);
        } else if(s[i] == ')' && rremove > 0){
            dfs(cur, i, lremove, rremove - 1, res);
        }

    }
}

vector<string> removeInvalidParentheses(string s){
    int lremove = 0, rremove = 0;
    for(char c : s){
        if(c == '('){
            lremove++;
        } else if(c == ')'){
            rremove = lremove == 0 ? rremove + 1 : rremove;
            lremove = lremove > 0 ? lremove - 1 : lremove;
        }
    }

    unordered_set<string> res;
    dfs(s, 0, lremove, rremove, res);
    return vector<string>(res.begin(), res.end());

}

int main(){
    string s = "()())()";
    vector<string> results = removeInvalidParentheses(s);

    for (const string& str : results) {
        cout << str << endl;
    }
    return 0;
}