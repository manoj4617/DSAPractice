#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    sort(candles.begin(), candles.end());
    int count = 0;
    for(int i=candles.size() - 1;i > 0;--i){
        int j = i - 1;
        if(candles[i] == candles[j]) count++;
    }
    return count+1;
}

int main(){
    vector<int> num;
    int n,v;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> v;
        num.push_back(v);
    }
    cout<<birthdayCakeCandles(num);
}