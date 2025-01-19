#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int kthSmallest(vector<int>& list, int k){
    priority_queue<int, vector<int>, less<int>> pq;

    // for(int i=0;i<k;++i){
    //     pq.push(list[i]);
    // }

    for(int i=0;i<list.size();++i){
        pq.push(list[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }

    return pq.top();
}

int main(){
    int k , n;
    cin >> n >> k;

    vector<int> list(n);

    for(int i=0;i<n;++i){
        cin >> list[i];
    }

    cout << kthSmallest(list,k);
    return 0;
}