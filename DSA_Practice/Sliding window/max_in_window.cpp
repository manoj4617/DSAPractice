#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> max_in_window(int num[], int n, int w){
    vector<int> res;
    deque<int> q;

    for(int i=0;i<w;++i){
        while(!q.empty() && num[i] > num[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    res.push_back(num[q.front()]);

    for(int i=w;i<n;++i){
        while(!q.empty() && num[i] >= num[q.back()]){
            q.pop_back();
        }
        if(!q.empty() && q.front() <= i - w){
            q.pop_front();
        }
        q.push_back(i);
        res.push_back(num[q.front()]);
    }
    return res;
}

int main(){
    int n,w;
    cin >> n >> w;
    int nums[n];
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }

    vector<int> res = max_in_window(nums,n,w);
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    return 0;
}