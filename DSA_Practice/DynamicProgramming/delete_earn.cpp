#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


map<int,int> points;
unordered_map<int,int> memo;

/**
 * This function takes an integer as input and returns the maximum
 * number of points that can be collected from the given set of
 * numbers. The function uses memoization to store the results of
 * previous computations so that they can be reused.
 *
 * The function recursively calls itself with decreasing values of
 * the input number until it reaches the base case of 0 or 1.
 *
 * At each step, the function computes the maximum number of points
 * that can be collected by taking the maximum of the following two
 * options: (1) the maximum number of points that can be collected by
 * not taking the current number, and (2) the number of points for the
 * current number plus the maximum number of points that can be
 * collected by taking the previous two numbers.
 *
 * The results of previous computations are stored in the memo map so
 * that they can be reused.
 */
int maxPointsHelper(int num){
    if(num == 0){
        return 0;
    }

    if(num == 1){
        return points.find(num) != points.end() ? points[num] : 0;
    }

    int gain = points[num];
    memo[num] = max(maxPointsHelper(num - 1), gain + maxPointsHelper(num - 2));
    return memo[num];
}

int maxPoints(vector<int>& nums) {
    // Find the maximum number in the input vector. This will be used to determine
    // the range of numbers that need to be considered when calculating the maximum points.
    int max_num = *max_element(nums.begin(), nums.end());

    // Iterate through each number in the input vector.
    for (int& num : nums) {
        // Add the value of the current number to the points map.
        // The points map keeps track of the total points that can be obtained for each number.
        // If a number appears multiple times in the input vector, its value is added multiple times.
        points[num] += num;
    }

    // Call the helper function with the maximum number found in the input vector.
    // The helper function calculates the maximum points that can be obtained by
    // considering all numbers up to the maximum number and returns the result.
    return maxPointsHelper(max_num);
}

/**
 * This function takes a vector of integers and returns the maximum
 * number of points that can be collected from the given set of
 * numbers. The function uses dynamic programming to store the
 * results of previous computations so that they can be reused.
 *
 * The function first iterates through each number in the input
 * vector and adds the value of the current number to the points map.
 * The points map keeps track of the total points that can be
 * obtained for each number. If a number appears multiple times in
 * the input vector, its value is added multiple times.
 *
 * The function then creates a dp array of size max_num + 1 and
 * initializes it with 0. The dp array will store the maximum points
 * that can be collected for each number from 0 to max_num.
 *
 * The function then iterates from 2 to max_num and for each number
 * i, it calculates the maximum points that can be collected by
 * taking the maximum of the following two options: (1) the maximum
 * points that can be collected by not taking the current number,
 * and (2) the number of points for the current number plus the
 * maximum points that can be collected by taking the previous two
 * numbers.
 *
 * The function returns the maximum points that can be collected for
 * the maximum number found in the input vector.
 */
int maxPointsDP(vector<int>& nums){
    int max_num = *max_element(nums.begin(), nums.end());

    // Iterate through each number in the input vector.
    for (int& num : nums) {
        // Add the value of the current number to the points map.
        // The points map keeps track of the total points that can be
        // obtained for each number. If a number appears multiple
        // times in the input vector, its value is added multiple
        // times.
        points[num] += num;
    }

    vector<int> dp(max_num + 1, 0);

    // Initialize dp[1] to be the number of points for the number 1
    dp[1] = points.find(1) != points.end() ? points[1] : 0;

    // Iterate from 2 to max_num
    for(int i = 2; i < dp.size() ; ++i){
        int gain = points.find(i) != points.end() ? points[i] : 0;
        // Calculate the maximum points that can be collected by
        // taking the maximum of the following two options: (1) the
        // maximum points that can be collected by not taking the
        // current number, and (2) the number of points for the
        // current number plus the maximum points that can be
        // collected by taking the previous two numbers.
        dp[i] = max(dp[i - 1], gain + dp[i - 2]);
    }
    // Return the maximum points that can be collected for the
    // maximum number found in the input vector.
    return dp[max_num];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }

    // cout << maxPoints(nums);
    cout << maxPointsDP(nums);
    return 0;
}