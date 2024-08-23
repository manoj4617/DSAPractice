#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/**
 * This function takes two parameters:
 * - num: an integer representing the number we want to extract a bit from.
 * - bit: an integer representing the position of the bit we want to extract.
 *
 * It returns an integer representing the value of the bit at the given position.
 * If the bit is set to 0, it returns 0. If the bit is set to 1, it returns 1.
 *
 * The function works by creating a mask with a single bit set to 1 at the desired position.
 * It then performs a bitwise AND operation between the mask and the input number.
 * If the result is 0, it means the bit is not set, so the function returns 0.
 * If the result is non-zero, it means the bit is set, so the function returns 1.
 */
int getBit(int num, int bit) {
    // Create a mask with a single bit set to 1 at the desired position.
    int mask = 1 << bit;

    // Perform a bitwise AND operation between the mask and the input number.
    int result = mask & num;

    // Check if the result is 0.
    if (result == 0) {
        // If the result is 0, the bit is not set, so return 0.
        return 0;
    } else {
        // If the result is non-zero, the bit is set, so return 1.
        return 1;
    }
}

// This function generates all possible subsets of a given set of integers.
// It takes a vector<int>& nums as input, which represents the set of integers.
// It returns a vector<vector<int>>, where each inner vector represents a subset.
vector<vector<int>> subsets(vector<int>& nums){
    // Initialize an empty vector to store the result.
    vector<vector<int>> res;

    // Check if the input set is empty.
    if(!nums.empty()){
        // Calculate the number of possible subsets by taking 2 raised to the power
        // of the number of integers in the set.
        long n = (long)(std::pow(2, nums.size()));

        // Iterate over each possible subset.
        for(int i=0;i<n ;++i){
            // Initialize an empty vector to store each subset.
            vector<int> temp;

            // Iterate over each integer in the set.
            for(int j=0;j<nums.size();j++){
                // Check if the j-th bit of the current subset is set.
                if(getBit(i,j) == 1){
                    // If the bit is set, add the corresponding integer to the subset.
                    int x = nums[j];
                    temp.push_back(x);
                }
            }
            // Add the current subset to the result vector.
            res.push_back(temp);
        }
    }
    else{
        // If the input set is empty, add an empty vector to the result vector.
        vector<int> empty;
        res.push_back(empty);
    }

    // Return the vector of all possible subsets.
    return res;
}

void Print2dvec(vector<vector<int>> vec){
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[i].size();++j){
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){

    std::vector<std::vector<int>> inputs = {{1,2,3},{2, 5, 7}, {1, 2, 3, 4}, {7, 3, 1, 5}};
        for (int i = 0; i < inputs.size(); i++) {
            std::vector<int> v = inputs[i];
            std::vector<std::vector<int>> subs;
            subs = subsets(v);
            Print2dvec(subs);
            std::cout<<std::string(100,'-')<<std::endl;
        };
}