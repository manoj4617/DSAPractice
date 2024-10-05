#include <iostream>
#include <vector>

using namespace std;

void swap_num(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;
}

/**
 * Finds the first missing positive integer in a given array of numbers.
 * The algorithm uses a cyclic sort algorithm to solve the problem.
 * The function first initializes an index i to 0.
 * It then enters a while loop that continues until i is equal to n-1.
 * Inside the loop, it checks if the value at index i is not equal to INT_MIN.
 * If the condition is true, then it calculates the correct spot for the value
 * at index i by subtracting 1 from the value.
 * It then checks if the value at index i is not equal to the value at the
 * correct spot, and if the correct spot is within the bounds of the array.
 * If both conditions are true, then it swaps the value at index i with the
 * value at the correct spot.
 * If the conditions are false, then it increments the index i.
 *
 * After the while loop, the function enters a for loop that iterates over
 * the array from index 0 to n-1.
 * Inside the loop, it checks if the value at the current index is not equal
 * to the index plus one.
 * If the condition is true, then it returns the index plus one as the first
 * missing positive integer.
 *
 * If the loop completes without finding a missing positive integer, then the
 * function returns n+1 as the missing positive integer.
 */
int FirstMissingPositive(vector<int>& nums){
    int i = 0;
    int correctSpot = 0;
    int n = nums.size();
    while(i < n){
        // If the value at index i is not equal to INT_MIN, then calculate the
        // correct spot for the value at index i by subtracting 1 from the value.
        if(nums[i] != INT_MIN){
            correctSpot = nums[i] - 1;
        }
        else{
            // If the value at index i is equal to INT_MIN, then set the correct
            // spot to be the value at index i.
            correctSpot = nums[i];
        }

        // Check if the value at index i is not equal to the value at the
        // correct spot, and if the correct spot is within the bounds of the
        // array.
        if(correctSpot >= 0 && correctSpot < nums.size() && nums[i] != nums[correctSpot]){
            // If both conditions are true, then swap the value at index i with
            // the value at the correct spot.
            swap_num(nums[i], nums[correctSpot]);
        }
        else{
            // If the conditions are false, then increment the index i.
            i++;
        }
    }

    // Iterate over the array from index 0 to n-1 and find the first missing
    // positive integer.
    for(int i=0;i<n;++i){
        if(i + 1 != nums[i]){
            // If the condition is true, then return the index plus one as the
            // first missing positive integer.
            return i + 1;
        }
    }
    // If the loop completes without finding a missing positive integer, then
    // return n+1 as the missing positive integer.
    return n + 1;
}


int main(){
    int n;
    cin >> n;
    vector<int>  num(n);
    for(int i=0;i<n;++i){
        cin >> num[i];
    }
    cout << FirstMissingPositive(num);
    return 0;
}