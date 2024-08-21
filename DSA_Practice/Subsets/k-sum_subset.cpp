#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief A recursive function to generate all subsets of the given set of
 * numbers that sum up to a given target number.
 *
 * @param cur_idx The current index in the given set of numbers.
 * @param cur_sum The current sum of numbers in the subset.
 * @param k The target number that we want to reach.
 * @param nums The given set of numbers.
 * @param res A vector of vectors to store all the subsets that sum up to the
 * target number.
 * @param cur_subset The current subset of numbers that we are generating.
 */
void BackTrace(int cur_idx,
                int cur_sum,
                int k,
                vector<int>& nums,
                vector<vector<int>>& res,
                vector<int>& cur_subset){
    // The base case: if the current sum is equal to the target number, we have
    // found a valid subset, so we add it to the result vector.
    //base case
    if(cur_sum == k){
        res.push_back(cur_subset);
        return;
    }

    // If the current sum is greater than the target number, we have reached a
    // dead end, so we return.
    if(cur_sum > k){
        return;
    }

    // Otherwise, we try to add the current number to the subset and recurse
    // with the updated sum and the next index in the set of numbers.
    for(int i=cur_idx;i<nums.size();++i){
        cur_subset.push_back(nums[i]);
        BackTrace(i+1, cur_sum + nums[i], k, nums, res, cur_subset);
        cur_subset.pop_back();
    }
}


void GetKSumSubset(int k, vector<int>& nums){
    int cur_sum = 0;
    int cur_idx = 0;
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur_subset;
    BackTrace(cur_idx, cur_sum, k, nums, res, cur_subset);

    for(auto& nu : res){
        for(auto& n : nu){
            cout << n << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> nums;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    GetKSumSubset(k, nums);
}