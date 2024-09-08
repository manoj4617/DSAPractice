#include <iostream>
#include <vector>

using namespace std;

/**
 * This function uses backtracking to generate all possible combinations of
 * numbers in the given set that sum up to a given target number.
 *
 * @param start The starting index in the given set of numbers.
 * @param combinations A vector of vectors to store all the generated combinations.
 * @param path A vector to store the current combination of numbers.
 * @param nums The given set of numbers.
 * @param target The target number that we want to reach.
 */
void Backtrack(int start, 
                vector<vector<int>>& combinations,
                vector<int> path,
                vector<int>& nums,
                int target)
{
    // If the current sum is equal to the target number, we have found a valid
    // combination, so we add it to the result vector and return.
    if(target == 0){
        combinations.push_back(path);
        return;
    }

    // Loop through the given set of numbers, starting from the current index.
    // We can start from the current index because we are allowed to use the same
    // number multiple times in the same combination.
    for(int i = start; i < nums.size();i++){
        // If the current number is less than or equal to the target number, we
        // can add it to the current combination and recurse with the updated sum
        // and the next index.
        if(nums[i] <= target){
            // Add the current number to the current combination.
            path.push_back(nums[i]);

            // Recurse with the updated sum and the next index. We can use the same
            // number multiple times in the same combination, so we pass the same
            // index to the recursive call.
            Backtrack(i, combinations, path, nums, target - nums[i]);

            // Remove the current number from the current combination, because we
            // have explored all the possible combinations that include this number.
            path.pop_back();
        }
    }
}


vector<vector<int>> CombinationSum(vector<int>& nums, int target){
    vector<vector<int>> combinations;
    vector<int> path;
    Backtrack(0,combinations, path, nums, target);
    return combinations;
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    vector<vector<int>>res = CombinationSum(nums, target);
    for(const auto& num : res){
        for(const auto& n : num){
            cout << n << " ";
        }

        cout << "\n";
    }
    return 0;
}