#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
        // If the input vector is empty, return 0, since there are no
        // consecutive numbers to find.
        if(nums.empty()) return 0;

        // Create a set of all numbers in the input vector. This set
        // will be used to quickly look up whether a number is in the
        // input vector.
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        // Iterate through each number in the set. If the number is the
        // start of a sequence (i.e., if the number before it is not in
        // the set), then count the length of the sequence starting at
        // this number.
        for(int num : s){
            if(!s.count(num - 1)){
                int len = 1;
                int curNum = num;
                // Count the length of the sequence starting at the
                // current number.
                while(s.find(curNum + 1) != s.end()){
                    len++;
                    curNum++;
                }
                // Update the longest sequence length found so far.
                longest = max(longest, len);
            }
        }
        // Return the longest sequence length found.
        return longest;
    }

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    cout << longestConsecutive(nums) << "\n";
    return 0;
}