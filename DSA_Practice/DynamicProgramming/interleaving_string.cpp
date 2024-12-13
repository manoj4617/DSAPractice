#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int backtrack(int i, int j, int k, string& s1, string& s2, string& s3){
    if(k == s3.length()){
        return (i == s1.length() && j == s2.length());
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    bool res = false;
    if(i < s1.length() && s1[i] == s3[k]){
        res = backtrack(i + 1, j, k + 1, s1,s2,s3);
    }
    if(!res && j < s2.length() && s2[j] == s3[k]){
        res = backtrack(i, j + 1, k + 1, s1,s2,s3);
    }

    dp[i][j] = res;
    return res;
}

bool interleave(string& s1, string& s2, string& s3){
    int l1 = s1.length();
    int l2 = s2.length();
    if(l1 + l2 != s3.length()){
        return false;
    }
    dp = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
    return backtrack(0,0,0,s1,s2,s3);
}

int main(){
    string s1,s2,s3;
    cin >> s2 >> s2 >> s3;

    cout << "Can interleave: " << s1 << " and: " << s2 << " to form: " << s3 << " " <<interleave(s1,s2,s3) << endl;

}