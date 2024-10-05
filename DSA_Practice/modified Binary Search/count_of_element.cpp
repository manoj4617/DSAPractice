#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and an integer k, and returns
 * the count of k in the vector.
 *
 * The function first finds the first and last occurance of k in the vector
 * using a modified binary search algorithm. The modified binary search
 * algorithm takes a boolean firstOccurance that is true if it is trying to
 * find the first occurance of k, and false if it is trying to find the last
 * occurance of k.
 *
 * The algorithm starts by setting low to 0 and high to the size of the vector
 * minus 1. It then enters a while loop that continues until low is greater
 * than high. In each iteration of the while loop, the algorithm calculates
 * mid as the average of low and high. If the element at mid is equal to k, the
 * algorithm sets res to mid and changes low or high depending on whether it
 * is trying to find the first or last occurance of k. If the element at mid
 * is greater than k, the algorithm sets high to mid - 1. If the element at
 * mid is less than k, the algorithm sets low to mid + 1.
 *
 * The algorithm then returns res.
 *
 * The function then uses the modified binary search algorithm to find the
 * first and last occurance of k, and returns the difference between the
 * first and last occurance plus one.
 */
int countOfElement(vector<int>& nums, int k){
    auto occurance = [&](bool firstOccurance) -> int{
        int low = 0;
        int high = nums.size() - 1;
        int res = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == k){
                res = mid;
                if(firstOccurance){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else if(nums[mid] > k){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    };

    int first = occurance(true);
    int last;
    if(first != -1){
        last = occurance(false);
    }
    return last - first + 1;
}

int main(){
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cin >> k;
    cout << "Element count: " << countOfElement(nums, k) << "\n";
    return 0;
}