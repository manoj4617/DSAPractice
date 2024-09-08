#include <iostream>
#include <vector>

using namespace std;

/**
 * This function uses backtracking to generate all possible subsets of
 * a given set of integers that sum up to a given target number.
 *
 * @param set The given set of integers.
 * @param subset A vector to store the current subset of integers being generated.
 * @param i The current index in the given set of integers.
 * @param target The target number that we want to reach.
 */

 int count = 0;
void Backtrack(vector<int>& set, vector<int>& subset, int i, int target){
    // If the current sum is equal to the target number, we have found a valid
    // subset, so we print it out and return.
    if(target == 0){ 
        // Print the current subset of integers.
        for(const int& s : subset){
            cout << s << " ";
        }
        cout << "\n";
        
        // Return from the function.
        return;
    }

    // If we have reached the end of the given set of integers, we have
    // explored all the possible subsets that start with the current subset,
    // so we return.
    if(i == set.size() - 1) return;

    // If the current integer is less than or equal to the target number, we
    // can add it to the current subset and recurse with the updated sum and
    // the next index.
    if(set[i] <= target){
        // Add the current integer to the current subset.
        subset.push_back(set[i]);

        // Recurse with the updated sum and the next index. We pass the same
        // index to the recursive call because we are allowed to use the same
        // integer multiple times in the same subset.
        Backtrack(set, subset, i + 1, target - set[i]);

        // Remove the current integer from the current subset, because we
        // have explored all the possible subsets that include this integer.
        subset.pop_back();
    }

    // Recurse with the next index.
    Backtrack(set, subset, i + 1, target);
}


int SubSetSum(vector<int>& set, int target){
    vector<int> subsets;
    Backtrack(set, subsets, 0, target);

    if(subsets.empty())
        return 0;
    else
        return 1;
}

int main(){
    int n ,t ;
    cin >> n >>t;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << SubSetSum(nums, t);
}