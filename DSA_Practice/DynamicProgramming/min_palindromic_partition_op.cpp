#include <iostream>
#include <vector>

using namespace std;


bool isPlindrome(string& s, int i , int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
//memoization
int MCM(string& s, int i, int j, vector<int>& dp){
    if(i >= j || isPlindrome(s,i,j)){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        if(isPlindrome(s,i,k)){
            int temp = MCM(s, k + 1, j,dp) + 1;
            ans = min(ans, temp);
        }
    }
    dp[i]= ans;
    return ans;
} 
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1, -1);
    return MCM(s, 0 , n-1, dp);
}

int main(){
    string s;
    cin >> s;
    cout << minCut(s);
    return 0;
}