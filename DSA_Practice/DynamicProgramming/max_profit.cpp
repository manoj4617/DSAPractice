#include<iostream>
#include<vector>

using namespace std;

int max_profit(vector<int> p){
    int mp = 0,left = 0, right = 1,profit;
    while(right < p.size()){
        if(p[left] < p[right]){
            profit = p[right] - p[left];
            mp = max(mp,profit);
        }
        else{
            left = right;
        }
        right++;
    }
    return mp;
}

int main(){
    int n,temp;
    cin >> n;
    vector<int> p;
    for(int i=0;i<n;++i){
        cin >> temp;
        p.push_back(temp);
    }
    cout << max_profit(p);
}