#include <iostream>
#include <vector>

using namespace std;

int removeMaxtwoDuplicates(vector<int> &nums){

    int writeIndex = 1;  // Keep track of where to write allowed elements
    int count = 1;      // Count the occurrences of the current element

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            count++; 
        } else {
            count = 1; // Reset count for a new element
        }

        // If count is within the limit, write the element 
        if (count <= 2) {
            nums[writeIndex++] = nums[i]; 
        }
    }

    return writeIndex;
}

int main(){

    int n;
    vector<int>nums;

    cin >> n;

    for(int i=0;i<n;++i){
        int t ;
        cin >> t;
        nums.push_back(t);
    }

    cout << removeMaxtwoDuplicates(nums);
    return 0;
}