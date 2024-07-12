#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;



class myComparator{
    public:
    bool operator() (pair<string,int>& pq, pair<string,int >& pq1){
        if(pq.second == pq1.second){
            return pq.first > pq1.first; 
        }
        return pq.first < pq1.first;
    }
};
vector<string> kFrequentWords(vector<string>& words, int k){
    priority_queue<pair<string, int>,
                        vector<pair<string, int>>,
                        myComparator> pq;

    unordered_map<string, int> mp;

    for(auto &word: words){
        mp[word]++;
    }

    for(auto &pr : mp){
        pq.push(make_pair(pr.first, pr.second));
    }

    vector<string> res;

    for(int i=k-1;i >= 0;i--){
        res.push_back(pq.top().first);
        pq.pop();
    }

    return res;
}