#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and an integer sum as input, and
 * returns the number of subsets of the given vector that sum up to the given
 * sum.
 *
 * The function uses a dynamic programming approach to solve the problem. It
 * creates a 2D vector dp of size (n+1) x (sum+1), where dp[i][j] is the number
 * of subsets of the first i integers of the given vector that sum up to j.
 *
 * The function initializes dp[0][0] to 1, which is the base case of the
 * dynamic programming approach. This is because there is always one subset of
 * the empty set that sums up to 0.
 *
 * The function then iterates over the elements of the given vector, and for
 * each element, it iterates over each possible sum from 0 to sum. For each
 * pair of element and sum, the function checks if the current element is less
 * than or equal to the current sum. If it is, the function sets dp[i][j] to be
 * the sum of dp[i-1][j-arr[i-1]] and dp[i-1][j]. This is because the current
 * element can be included in the subset or not included in the subset. If the
 * current element is not included in the subset, the sum of the subset is
 * dp[i-1][j]. If the current element is included in the subset, the sum of the
 * subset is dp[i-1][j-arr[i-1]].
 *
 * If the current element is not less than or equal to the current sum, the
 * function sets dp[i][j] to be dp[i-1][j]. This is because the current element
 * can't be included in the subset.
 *
 * Finally, the function returns dp[n][sum], which is the number of subsets of
 * the given vector that sum up to the given sum.
 */
int subsetSum(vector<int>& arr,int sum){
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    dp[0][0] = 1;

    for(int i=1;i<=n;++i){
        for(int j=0;j<=sum;++j){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

/**
 * This function takes a vector of integers and an integer difference as input,
 * and returns the number of subsets of the given vector that have a sum equal
 * to the given difference plus half the sum of all the elements in the vector.
 *
 * The algorithm works by first calculating the sum of all the elements in the
 * given vector. It then checks if the given difference plus the sum of all the
 * elements in the vector is odd. If it is, the function returns 0, since there
 * can be no subset of the given vector that sums up to an odd number.
 *
 * If the given difference plus the sum of all the elements in the vector is
 * even, the function calculates the subset sum sub that is equal to half the
 * given difference plus the sum of all the elements in the vector. It then
 * calls the subsetSum function to get the number of subsets of the given vector
 * that sum up to sub, and returns this number.
 */
int subsetCountWithDiff(vector<int>& arr, int diff){
    int sum = 0;
    for(int i : arr){
        // Calculate the sum of all the elements in the given vector.
        sum += i;
    }

    // If the given difference plus the sum of all the elements in the vector
    // is odd, return 0, since there can be no subset of the given vector that
    // sums up to an odd number.
    if((diff + sum) % 2 != 0)
        return 0;

    // Calculate the subset sum sub that is equal to half the given difference
    // plus the sum of all the elements in the vector.
    int sub = (diff + sum) / 2;

    // Call the subsetSum function to get the number of subsets of the given
    // vector that sum up to sub, and return this number.
    int res = subsetSum(arr, sub);
    return res;
}


int main(){
    int n,d;
    cin >> n >> d;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cout <<subsetCountWithDiff(nums, d);
    return 0;
}