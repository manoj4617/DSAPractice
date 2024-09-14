#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and an integer range as input and
 * returns a vector of integers that represent the subset sums of the given
 * vector that are less than or equal to the given range.
 *
 * @param nums The given vector of integers.
 * @param range The given integer range.
 * @return A vector of integers representing the subset sums of the given
 * vector that are less than or equal to the given range.
 */
vector<int> subset_sum(vector<int>& nums, int range){
    int n = nums.size();

    // Create a vector dp of size range + 1 with all elements initialized to
    // false. This vector is used to store the solutions to all subproblems.
    vector<bool> dp(range + 1, false);

    // Create a temporary vector temp of size range + 1 with all elements
    // initialized to false. This vector is used to store the solutions to all
    // subproblems of the current iteration.
    vector<bool> temp(range + 1, false);

    // The base case of the dynamic programming approach is that the sum of an
    // empty subset is 0. Therefore, set dp[0] to true.
    dp[0] = true;
    temp[0] = true;

    // Iterate over each element in the given vector.
    for(int i=1;i<=n;++i){

        // Iterate over each possible sum from 1 to range.
        for(int j=1;j<=range;++j){

            // If the current element is less than or equal to the current sum,
            // then we have two options: either include the current element in
            // the subset, or not include the current element in the subset.
            if(nums[i - 1] <= j){

                // If we include the current element in the subset, the maximum
                // sum that can be obtained is the sum of the current element
                // and the maximum sum that can be obtained by considering the
                // remaining elements and the remaining sum j - nums[i-1].
                // Therefore, set temp[j] to true if dp[j - nums[i-1]] is true
                // or dp[j] is true.
                temp[j] = dp[j - nums[i-1]] || dp[j];
            }
        }

        // After considering all possible sums from 1 to range, update dp
        // with the solutions to all subproblems of the current iteration.
        dp = temp;
    }

    // Create a vector set to store the subset sums of the given vector that
    // are less than or equal to the given range.
    vector<int> set;

    // Iterate over each possible sum from 1 to range/2.
    for(int i = 1;i <= range/2;++i){

        // If the current sum is a subset sum of the given vector, add it to
        // the set.
        if(dp[i] == true){
            set.push_back(i);
        }
    }

    // Return the set of subset sums of the given vector that are less than
    // or equal to the given range.
    return set;
}

/**
 * This function takes a vector of integers as input and returns the
 * minimum difference between the sum of any subset of the given vector
 * and the sum of the remaining elements in the vector.
 *
 * @param nums The given vector of integers.
 * @return The minimum difference between the sum of any subset of the
 * given vector and the sum of the remaining elements in the vector.
 */
int MinSubsetDiff(vector<int>& nums){
    /**
     * Calculate the total sum of all the elements in the given vector.
     * This will be used later to calculate the sum of the remaining elements
     * in the vector.
     */
    int sum=0;
    for(auto& n : nums){
        sum += n;
    }

    /**
     * Use the subset_sum function to generate all the possible subsets of the
     * given vector that sum up to the total sum. The subset_sum function returns
     * a vector of integers, where each integer represents the sum of a subset of
     * the given vector.
     */
    vector<int> possible_sets = subset_sum(nums, sum);

    /**
     * Initialize the minimum difference to a very large number. This will be
     * used to store the minimum difference between the sum of any subset of the
     * given vector and the sum of the remaining elements in the vector.
     */
    int diff = INT_MAX;

    /**
     * Iterate over all the possible subsets of the given vector and calculate
     * the difference between the sum of each subset and the sum of the remaining
     * elements in the vector. Update the minimum difference if the current
     * difference is smaller.
     */
    for(auto& d : possible_sets){
        diff = min(diff, abs(sum - (2 * d)));
    }

    /**
     * Return the minimum difference between the sum of any subset of the given
     * vector and the sum of the remaining elements in the vector.
     */
    return diff;
}


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cout << MinSubsetDiff(nums);
    return 0;
}