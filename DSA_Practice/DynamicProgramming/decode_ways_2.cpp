#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9+7;
long long Backtrack(string& s, int i, vector<int>& dp){
    if(i >= s.size()){
        return 1;
    }

    if(s[i] == '0'){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    long long count = 0;

    if(s[i] == '*'){
        count += 9 * Backtrack(s, i + 1, dp);
        if(i+1 < s.size()){
            if(s[i + 1] == '*'){
                count += 15 * Backtrack(s, i + 2, dp);
            }
            else if(s[i + 1] >= '0' && s[i + 1] <= '6'){
                count += 2 * Backtrack(s, i + 2, dp);
            }
            else {
                count += Backtrack(s,i+2,dp);
            }
        }
    }
    else{
        count += Backtrack(s, i+1, dp);
        if(i+1 < s.size()){
            if(s[i] == '1'){
                if(s[i+1] == '*'){
                    count += 9 * Backtrack(s, i+2, dp);
                }
                else{
                    count += Backtrack(s, i+2, dp);
                }
            }
            if(s[i] == '2'){
                if(s[i+1] == '*'){
                    count += 6 * Backtrack(s, i+2, dp);
                }
                else if(s[i+1] >= '0' && s[i+1] <= '6'){
                    count += Backtrack(s, i+2, dp);
                }
            }
        }
    }
    return dp[i] = (count % mod);
}

int Decode(string& s){
    vector<int> dp(s.size(), -1);
    return (int)Backtrack(s,0,dp);
}

int main(){
    string s;
    cin >> s;
    cout << Decode(s);
    return 0;
}