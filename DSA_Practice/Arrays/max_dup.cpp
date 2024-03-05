#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool findMaxDup(vector<int> nums){
    map<int,int> hash;

    for(int i=0;i<nums.size();++i){
        hash[nums[i]]++;
    }
    map<int,int>::iterator map_it = hash.begin();

    for(;map_it != hash.end();++map_it){
        if(map_it->second >= 2){
            return true;
        }
    }
    return false;
}

int main(){
    int n,temp;
    cin >> n;
    vector<int> nums;

    for(int i=0;i<n;++i){
        cin >> temp;
        nums.push_back(temp);
    }

    cout << findMaxDup(nums);
}