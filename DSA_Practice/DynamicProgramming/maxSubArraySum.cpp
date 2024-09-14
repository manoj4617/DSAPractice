#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and returns the maximum
 * subarray sum of all the subarrays of the given vector.
 *
 * The algorithm is to keep track of two variables: 'maxSum' and 'res'.
 * 'maxSum' is the maximum sum of the subarray ending at the current
 * position and 'res' is the maximum sum of any subarray seen so far.
 *
 * The algorithm works by iterating through the vector and at each
 * iteration, it calculates the maximum sum of the subarray ending at
 * the current position by taking the maximum of the current sum and
 * the current element. It then updates 'res' to be the maximum of
 * 'maxSum' and 'res'.
 *
 * At the end of the algorithm, 'res' is the maximum sum of any subarray
 * of the given vector.
 */
int MaxSumSubArray(vector<int> &nums){
    int n = nums.size();
    int maxSum = nums[0];
    int res = nums[0];

    for(int i=1;i<n;++i){
        // Calculate the maximum sum of the subarray ending at the
        // current position by taking the maximum of the current
        // sum and the current element
        maxSum = max(maxSum + nums[i], nums[i]);

        // Update 'res' to be the maximum of 'maxSum' and 'res'
        res = max(maxSum, res);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cout << MaxSumSubArray(nums);
    return 0;
}