#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, int idx , vector<int>& subset, vector<vector<int>>& res){
    if(idx >= nums.size()){
        res.push_back(subset);
        return;
    }

    // choose the current element
    subset.push_back(nums[idx]);
    dfs(nums, idx + 1, subset, res);

    // not choose the current element
    subset.pop_back();
    dfs(nums, idx + 1, subset, res);
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> subset;
    dfs(nums, 0, subset, res);
    return res;
}

int main(){
    vector<int> nums = {2,4,6,8,9};
    vector<vector<int>> res = subsets(nums);
    for(auto i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}