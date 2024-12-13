#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void backtrack(vector<int>& nums, unordered_map<int,int>& mp, vector<vector<int>>& res, vector<int>& path, int idx){
    // Base case: if the current path length is equal to the original nums size,
    // a complete permutation has been formed.
    if(idx == nums.size()){
        // Add the current permutation to the result list.
        res.push_back(path);
        return;
    }
    
    // Iterate over each unique number in the frequency map.
    for(auto& x : mp){
        int num = x.first;   // Current number to consider
        int count = x.second;// Remaining count of the current number
        
        // If the current number is exhausted, skip it.
        if(count == 0){
            continue;
        }
        
        // Include the current number in the current path.
        path.push_back(num);
        // Decrease the count of the current number as it's used.
        mp[num]--;
        
        // Recursively build permutations with the remaining numbers.
        backtrack(nums, mp, res, path, idx + 1);
        
        // Backtrack: remove the current number from the path.
        path.pop_back();
        // Restore the count of the current number for future permutations.
        mp[num]++;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int& n : nums){
        mp[n]++;
    }
    vector<int> path;
    vector<vector<int>> res;
    backtrack(nums,mp,res,path, 0);
    return res;
}

int main(){
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = permuteUnique(nums);
    for(auto& v : res){
        for(auto& n : v){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}