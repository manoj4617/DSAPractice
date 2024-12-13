#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void dfs(vector<int>& candidates, int idx, vector<int>& path, set<vector<int>>& res, int target, int sum){
    if(target == sum){
        res.insert(path);
        return;
    }
    
    for(int i=idx;i<candidates.size();i++){
        //avoid duplicates
        if(i > idx  && candidates[idx] == candidates[idx + 1]){
            idx++;
            continue;
        }
        if(sum + candidates[i] > target){
            break;
        }
        path.push_back(candidates[i]);
        dfs(candidates, i + 1, path, res, target, sum + candidates[i]);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    set<vector<int>> res;
    vector<int> path;
    dfs(candidates, 0, path, res, target, 0);
    return vector<vector<int>>(res.begin(), res.end());
}

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
    for(auto i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}