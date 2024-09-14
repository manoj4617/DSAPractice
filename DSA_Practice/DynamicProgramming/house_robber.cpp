#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function takes a vector of integers and returns the maximum amount of money that can be
 * stolen from the houses in the vector, with the constraint that no two adjacent houses can be stolen
 * from.
 *
 * @param nums A vector of integers representing the amount of money in each house.
 *
 * @return An integer representing the maximum amount of money that can be stolen.
 */
int HouseRobber(vector<int> &nums){
    /**
     * prev is the maximum amount of money that can be stolen if the current house is not stolen from.
     * cur is the maximum amount of money that can be stolen if the current house is stolen from.
     * next is the maximum amount of money that can be stolen if the next house is not stolen from.
     */
    int prev = 0;
    int cur = 0;
    int next = 0;
    int n = nums.size();

    /**
     * Iterate through the vector of houses and calculate the maximum amount of money that can be
     * stolen for each house.
     */
    for(int i=0;i<n;++i){
        /**
         * next is the maximum of the current maximum amount of money that can be stolen if the
         * current house is not stolen from, and the maximum amount of money that can be stolen if
         * the current house is stolen from, plus the amount of money in the current house.
         */
        next = max(prev + nums[i], cur);

        /**
         * Update prev and cur to be ready for the next iteration.
         */
        prev = cur;
        cur = next;
    }

    /**
     * Return the maximum amount of money that can be stolen from the vector of houses.
     */
    return cur;
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
    cout << HouseRobber(nums);
    return 0;
}