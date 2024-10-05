#include <iostream>
#include <vector>

using namespace std;

void swap_num(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;
}

/**
 * Finds the missing number in a given array of numbers from 0 to n inclusive.
 * The array is expected to contain all numbers from 0 to n inclusive except one.
 * The function uses a cyclic sort algorithm to solve the problem.
 *
 * The function first initializes an index i to 0.
 * It then enters a while loop that continues until i is equal to n.
 * Inside the loop, it checks if the value at index i is less than n and
 * if the value at index i is not equal to the value at index nums[i].
 * If the condition is true, then it swaps the value at index i with the
 * value at index nums[i].
 * If the condition is false, then it increments the index i.
 *
 * After the while loop, the function enters a for loop that iterates over
 * the array from index 0 to n-1.
 * Inside the loop, it checks if the value at index i is not equal to i.
 * If the condition is true, then it returns i as the missing number.
 *
 * If the loop completes without finding a missing number, then the function
 * returns n as the missing number.
 */
int MissingNumber(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    while(i < n){
        // Swap the value at index i with the value at index nums[i]
        // if the value at index i is less than n and the value at index
        // i is not equal to the value at index nums[i].
        int value = nums[i];
        if(value < n && value != nums[value]){
            swap_num(nums[i], nums[value]);
        }
        else{
            // If the condition is false, then increment the index i.
            i++;
        }
    }

    // Iterate over the array from index 0 to n-1 and find the missing number.
    for(int i =0;i<n;++i){
        if(i != nums[i]){
            return i;
        }
    }

    // If the loop completes without finding a missing number, then return n
    // as the missing number.
    return nums.size();
}

int main(){
    int n;
    cin >> n;
    vector<int>  num(n);
    for(int i=0;i<n;++i){
        cin >> num[i];
    }
    cout << MissingNumber(num);
    return 0;
}