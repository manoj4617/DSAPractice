#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief Function to count the number of complete subarrays in an array
 *
 * @param nums is the input array
 *
 * @return the number of complete subarrays
 *
 * Time complexity: O(n), where 'n' is the length of 'nums'
 * Space complexity: O(m), where 'm' is the number of distinct elements in 'nums'
 */
int countCompleteSubarrays(vector<int>& nums) {
        // 'mp_count' maps each distinct element in 'nums' to its frequency
        unordered_map<int, int> mp_count;

        // Count the frequency of each element in 'nums'
        for(auto n : nums){
            mp_count[n]++;
        }

        // 'count' will store the final answer
        int count = 0;

        // 'mp' maps each distinct element in the current window of 'nums' to its
        // frequency
        unordered_map<int , int>mp;

        // 'start' and 'end' are two pointers used to slide the window of 'nums'
        int start = 0, end = 0;

        // Keep expanding the right side of the window while keeping the left side
        // fixed until we cover the entire 'nums'
        while(end < nums.size()){

            // Add the current element in 'nums' to 'mp'
            mp[nums[end]]++;

            // While the size of 'mp' is equal to the number of distinct elements
            // in 'nums' (i.e., we have a complete subarray),
            while(mp.size() == mp_count.size()){

                // Remove the element at 'start' from 'mp' as we no longer need
                // it
                mp[nums[start]]--;

                // If the frequency of the element at 'start' becomes 0, it means
                // we have removed the last occurrence of that element in 'mp', so
                // we should erase it from 'mp'
                if(mp[nums[start]] == 0)
                    mp.erase(nums[start]);

                // Move the left side of the window forward by 1
                start++;

                // Increment 'count' by the length of the window as we have found
                // a complete subarray
                count += nums.size() - end;
            }

            // Move the right side of the window forward by 1
            end++;
        }

        return count;
}

int main(){

    vector<int> nums;
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    cout << countCompleteSubarrays(nums);

    return 0;

}