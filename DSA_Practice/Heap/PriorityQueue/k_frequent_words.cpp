#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;



class myComparator{
    public:
    /**
     * This is a custom comparator for the priority queue. It is used to compare
     * two pairs of strings and integers. The first element of the pair is the
     * string representing a word, and the second element is the frequency of
     * the word in the input vector.
     *
     * The comparator first compares the frequencies of the words. If the
     * frequencies are equal, it compares the words themselves in lexicographical
     * order. If the words are equal, it returns false.
     *
     * The reason for this comparison is that the priority queue is a max heap,
     * and we want the word with the highest frequency to be at the top of
     * the heap. If the frequencies are equal, we want the word that comes
     * first in lexicographical order to be at the top of the heap.
     */
    bool operator() (pair<string,int>& pq, pair<string,int >& pq1){
        if(pq.second == pq1.second){
            // If the frequencies are equal, compare the words
            return pq.first > pq1.first; 
        }
        // If the frequencies are not equal, compare them
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