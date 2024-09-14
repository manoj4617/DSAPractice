#include <iostream>
#include <vector>

using namespace std;

int HouseRobberHelper(vector<int> &nums){
    int p = 0;
    int c = 0;
    int n = 0;

    int len = nums.size();

    for(int i=0;i<len;++i){
        n = max(p + nums[i], c);
        p = c;
        c = n;
    }

    return c;
}

/**
 * @brief This function takes a vector of integers and returns the maximum amount of money
 * that can be stolen from the houses in the vector, with the constraint that no two adjacent
 * houses can be stolen from.
 *
 * @param nums A vector of integers representing the amount of money in each house.
 *
 * @return An integer representing the maximum amount of money that can be stolen.
 */
int HouseRobber2(vector<int> &nums){
    /**
     * num1 is a vector containing all the elements of nums except the last one.
     * num2 is a vector containing all the elements of nums except the first one.
     * This is done to consider two cases: one where the first house is not stolen from,
     * and one where the last house is not stolen from.
     */
    vector<int> num1(nums.begin() , nums.end() - 1);
    vector<int> num2(nums.begin() + 1, nums.end());

    /**
     * Call the helper function on num1 and num2, and return the maximum of the two results.
     * The helper function takes a vector of integers and returns the maximum amount of money
     * that can be stolen from the houses in the vector, with the constraint that no two adjacent
     * houses can be stolen from.
     */
    return max(HouseRobberHelper(num1), HouseRobberHelper(num2));
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    cout << HouseRobber2(nums);
    return 0;
}