#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Returns all unique triplets that sum to 0 in the given sorted array
 * 
 * @param nums Sorted array of integers
 * @return vector<vector<int>> All unique triplets that sum to 0
 */
vector<vector<int>> three_sum(vector<int>& nums){
    
    // Resultant triplets
    vector<vector<int>> res;
    
    // Sort the input array
    sort(nums.begin(), nums.end());
    
    // Loop through the array from start to one position before the end,
    // to avoid duplicate triplets 
    for(int i=0; i<nums.size()-2; ++i){
        
        // Index of the lowest element in the triplet
        int low = i + 1;
        
        // Index of the highest element in the triplet
        int high = nums.size() - 1;
        
        // Loop through the array from one position after the lowest element
        // to the end, to find the other two elements that sum to 0
        while(low < high){
            
            // The sum of the three elements
            int triplet = nums[i] + nums[low] + nums[high];
            
            // If the sum is equal to 0
            if(triplet == 0){
                
                // Create a vector to hold the triplet
                vector<int> new_triplet = {nums[i], nums[low], nums[high]};
                
                // Sort the triplet to avoid duplicates
                sort(new_triplet.begin(), new_triplet.end());
                
                // Check if the current triplet is already in the resultant vector
                bool exists = false;
                for(const auto& t : res){
                    
                    // If the current triplet is already in the resultant vector
                    if(t == new_triplet){
                        
                        // Set the exists flag to true
                        exists = true;
                        
                        // Break out of the loop early
                        break;
                    }
                }
                
                // If the current triplet is not already in the resultant vector
                if(!exists){
                    
                    // Add the current triplet to the resultant vector
                    res.push_back(new_triplet);
                }
            }
            
            // If the sum is less than 0, increment the lowest element index
            // to find a new pair that sums to a value closer to 0
            if(triplet < 0)
                low += 1;
            
            // If the sum is greater than 0, decrement the highest element index
            // to find a new pair that sums to a value closer to 0
            else
                high -= 1;
        }
    }
    
    // Return the resultant vector of unique triplets
    return res;
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

    vector<vector<int>> res = three_sum(nums);

    for(const auto& triplet : res){
        for(auto& t : triplet){
            cout  << t << " ";
        }
        cout << "\n";
    }

    return 0;
}

