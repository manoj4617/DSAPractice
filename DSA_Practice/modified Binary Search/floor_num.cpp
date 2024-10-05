#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and an integer k, and returns
 * the floor of k in the vector. The floor of k is the largest element in
 * the vector that is less than or equal to k.
 *
 * The function works by using a binary search on the vector. It starts by
 * setting low to 0 and high to the size of the vector minus 1. It then enters
 * a while loop that continues until low is greater than high.
 *
 * In each iteration of the loop, the function calculates the midpoint of the
 * current search window as mid = low + (high - low) / 2.
 *
 * If the element at mid is equal to k, the function returns the element at
 * mid as the floor of k.
 *
 * If the element at mid is less than k, then the floor of k is in the right
 * half of the search window, so the function sets res to the element at mid
 * and sets low to mid + 1.
 *
 * If the element at mid is greater than k, then the floor of k is in the left
 * half of the search window, so the function sets high to mid - 1.
 *
 * The function then repeats the loop until the search window is empty, at
 * which point it returns the last value of res as the floor of k.
 */
int floor_num(vector<int>& nums, int k){
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == k){
            return nums[mid];
        }
        if(nums[mid] < k){
            res = nums[mid];
            low = mid + 1;
        }
        else if(nums[mid] > k){
            high = mid - 1;
        }
    }
    return res;
}

/**
 * This function takes a vector of integers and an integer k, and returns
 * the ceil of k in the vector. The ceil of k is the smallest element in
 * the vector that is greater than or equal to k.
 *
 * The function works by using a binary search on the vector. It starts by
 * setting low to 0 and high to the size of the vector minus 1. It then enters
 * a while loop that continues until low is greater than high.
 *
 * In each iteration of the loop, the function calculates the midpoint of the
 * current search window as mid = low + (high - low) / 2.
 *
 * If the element at mid is equal to k, the function returns the element at
 * mid as the ceil of k.
 *
 * If the element at mid is less than k, then the ceil of k is in the right
 * half of the search window, so the function sets low to mid + 1.
 *
 * If the element at mid is greater than k, then the ceil of k is in the left
 * half of the search window, so the function sets high to mid - 1 and sets
 * res to the element at mid.
 *
 * The function then repeats the loop until the search window is empty, at
 * which point it returns the last value of res as the ceil of k.
 */
int ceil_num(vector<int>& nums, int k){
    int low = 0;
    int high = nums.size() - 1;
    int res = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == k){
            return nums[mid];
        }

        if(nums[mid] < k){
            low = mid + 1;
        }
        else if(nums[mid] > k){
            res = nums[mid];
            high = mid - 1;
        }
    }
    return res;
}

int main() {

    int n, k;
    cin >> n;
    vector<int> nums(n);

    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cin >> k;

    cout << "Floor: " << floor_num(nums, k) << "\n";
    cout << "Ceil: " << ceil_num(nums, k) << "\n";
    return 0;
}