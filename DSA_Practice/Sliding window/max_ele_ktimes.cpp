#include <iostream>
#include <vector>

using namespace std;

// This function calculates the number of subarrays with exactly k elements equal to the maximum element in the array.
// The function takes in a vector of integers and an integer k.
// The function iterates through the vector and keeps track of the maximum element in the array.
// The function then starts two pointers, start and end, at the beginning and end of the array respectively.
// The function then iterates through the array until end reaches the end of the array.
// For each iteration, if the element at end is equal to the maximum element, the function increments a count of the number of elements equal to the maximum element.
// If the count is equal to k, the function decrements the count by iterating through the array from start to end, and for each element equal to the maximum element, the function decrements the count. The function then advances start by 1.
// The function then calculates the number of subarrays with exactly k elements equal to the maximum element by adding the value of start to a running total of subarrays.
// The function returns the number of subarrays.
long long countSubarrays(vector<int>& nums, int k) {
        long long subArray = 0; // The running total of subarrays with exactly k elements equal to the maximum element
        int count = 0; // The number of elements equal to the maximum element in the subarray from start to end
        int start = 0; // The starting index of the subarray from start to end
        int end = 0; // The ending index of the subarray from start to end

        int maxNum = nums[0]; // The maximum element in the array
        
        for(auto &n : nums){ // Iterate through the array and find the maximum element
            if(n > maxNum){
                maxNum = n;
            }
        }

        while(end < nums.size()){ // Iterate through the array
            if(nums[end] == maxNum){ // If the element at end is equal to the maximum element, increment the count
                count++;
            }
            while(count == k){ // If the count is equal to k, decrement the count by iterating through the array from start to end
                if(nums[start] == maxNum){ // If the element at start is equal to the maximum element, decrement the count
                    count--;
                }
                start++; // Advance start by 1
            }
            subArray += start; // Calculate the number of subarrays with exactly k elements equal to the maximum element
            end++; // Advance end by 1
        }
        return subArray; // Return the number of subarrays with exactly k elements equal to the maximum element
    }

int main(){
    vector<int> nums;
    int n, k;
    cin >> n >> k;

    for( int i = 0; i < n; i++ ){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << countSubarrays(nums, k) << endl;
    return 0;
}