#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/**
 * This is a recursive function to generate all possible subsets of a given set of
 * integers with possible duplicates.
 *
 * @param nums The given set of integers.
 * @param idx The current index of the set being processed.
 * @param subset The current subset of integers being generated.
 * @param res The set to store all the generated subsets.
 */
void dfs(vector<int>& nums, int idx, vector<int>& subset, set<vector<int>>& res){
    // Base case: if the current index is greater than or equal to the size of the
    // given set of integers, we have explored all the possible subsets, so we add
    // the current subset to the result set and return.
    if(idx >= nums.size()){
        res.insert(subset);
        return;
    }

    // Recursive case: we have two choices, either include the current element in the
    // current subset or exclude it. We do both.

    // Include this element
    subset.push_back(nums[idx]);
    dfs(nums, idx + 1, subset, res);

    // Exclude this element
    subset.pop_back();

    // Skip duplicates
    while(idx + 1 < subset.size() && nums[idx] == nums[idx + 1]){
        idx++;
        // return;
    }

    // Recursively call the function with the next index.
    dfs(nums, idx + 1, subset, res);

}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> subset;
    set<vector<int>> res;
    dfs(nums, 0, subset, res);
    return vector<vector<int>>(res.begin(), res.end());
}

int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int>> res = subsetsWithDup(nums);
    for(auto i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}