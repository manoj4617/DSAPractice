#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int>> findSCSLength(string s1, string s2){
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp;
}

void findAllSCSs(string& s1, string& s2, int i, int j, string path, vector<vector<int>>& dp, unordered_set<string>& scsSet){
    if(i == 0){
        path = s2.substr(0,j) + path;
        scsSet.insert(path);
        return;
    }
    if(j == 0){
        path = s1.substr(0,i) + path;
        scsSet.insert(path);
        return;
    }

    if(s1[i-1] == s2[j-1]){
        findAllSCSs(s1, s2, i - 1 , j - 1, s1[i-1] + path, dp, scsSet);
    }
    else{
        if(dp[i][j] == dp[i-1][j]){
            findAllSCSs(s1,s2,i-1,j,s1[i-1] + path, dp, scsSet);
        }
        if(dp[i][j] == dp[i][j-1]){
            findAllSCSs(s1,s2,i,j-1,s2[j-1] + path, dp, scsSet);
        }
    }
}



vector<int> getCharFrequency(string s){
    vector<int> freq(26,0);
    for(char c : s){
        freq[c - 'a']++;
    }
    return freq;
}

unordered_set<string> findMultiSCS(vector<string> &words){
    unordered_set<string> scsSet;
    scsSet.insert(words[0]);

    for(int i=1;i<words.size();i++){
        unordered_set<string> newSet;
        for(string scs : scsSet){
            vector<vector<int>> dp = findSCSLength(scs, words[i]);
            findAllSCSs(scs, words[i], scs.length(), words[i].length(), "", dp, newSet);
        }
        scsSet = newSet;
    }
    return scsSet;
}

vector<vector<int>> getUniqueFrequencies(vector<string>& words){
    unordered_set<string> uniqueSCS = findMultiSCS(words);
    unordered_set<string> seenFreq;
    vector<vector<int>> res;

    for(string scs : uniqueSCS){
        vector<int> freq = getCharFrequency(scs);
        string freqKey;
        for(int f : freq) freqKey += to_string(f) + "#";

        if(seenFreq.find(freqKey) == seenFreq.end()){
            seenFreq.insert(freqKey);
            res.push_back(freq);
        }
    }
    return res;
}


vector<vector<int>> SCSFrequencies(vector<string>& words){
    return getUniqueFrequencies(words);
}

int main(){

    vector<string> words = {"ab", "ba"};
    vector<vector<int>> res = SCSFrequencies(words);

    for(auto vec : res){
        cout << "[" << " ";
        for(int i : vec){
            cout << i << " ";
        }
        cout << "]" << endl; 
    }
}


