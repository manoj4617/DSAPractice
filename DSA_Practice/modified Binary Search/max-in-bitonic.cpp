#include <concurrencysal.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs a binary search on a bitonic array.
 * The search is divided into two halves - the first half is searched in ascending order,
 * and the second half is searched in descending order.
 *
 * @param num The bitonic array to search.
 * @param low The lower bound of the search window.
 * @param high The upper bound of the search window.
 * @param k The value to search for.
 * @param asc A boolean indicating whether to search in ascending (true) or descending (false) order.
 * @return The index of k in the array, or -1 if k is not found.
 */
int BSearch(const vector<int>& num, int low , int high, int k, bool asc){
    // If the search window is empty, return -1 to indicate that k was not found.
    if(low > high){
        return -1;
    }
    // If the search window only contains one element, return that index.
    if(low == high){
        return low;
    }

    // Perform a binary search in the search window.
    while(low < high){
        int mid = low + (high - low) / 2;

        // If the value at the midpoint is equal to k, return its index.
        if(num[mid] == k){
            return mid;
        }
        // If the search is being performed in ascending order...
        if(asc){
            // ...and the value at the midpoint is greater than k...
            if(num[mid] > k){
                // ...then set the high pointer to the midpoint - 1 to narrow the search window.
                high = mid - 1;
            }
            // ...and the value at the midpoint is less than k...
            else {
                // ...then set the low pointer to the midpoint + 1 to narrow the search window.
                low = mid + 1;
            }
        }
        // If the search is being performed in descending order...
        else{
            // ...and the value at the midpoint is greater than k...
            if(num[mid] > k){
                // ...then set the low pointer to the midpoint + 1 to narrow the search window.
                low = mid + 1;
            }
            // ...and the value at the midpoint is less than k...
            else {
                // ...then set the high pointer to the midpoint - 1 to narrow the search window.
                high = mid - 1;
            }
        }
    }
    // If the search window is empty, then k is not in the array.
    return -1;
}

int find_peak(const vector<int>& num){
    int low = 0;
    int high = num.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if((mid == 0 || num[mid - 1] <= num[mid]) &&
            (mid == num.size() - 1 || num[mid] >= num[mid + 1])){
                return mid;
            }
        if(mid > 0 && num[mid - 1] > num[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

/**
 * Searches for a given value in a bitonic array.
 * The array is divided into two halves at the peak, and a binary search is performed
 * on each half. The first binary search is performed in ascending order, and the second
 * binary search is performed in descending order.
 *
 * @param num The bitonic array to search.
 * @param k The value to search for.
 * @return The index of k in the array, or -1 if k is not found.
 */
int SearchInBitonic(const vector<int>& num, int k){
    // Find the peak of the bitonic array.
    int peak = find_peak(num);

    // Perform a binary search on the ascending half of the array.
    int lh = BSearch(num, 0, peak, k, true);

    // If the value is found in the ascending half, return its index.
    if(lh != -1) return lh;

    // Perform a binary search on the descending half of the array.
    int rh = BSearch(num, peak + 1, num.size() - 1, k, false);

    // Return the index of k if found in the descending half, or -1 if k is not found.
    return rh;
}


int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i=0;i<n;++i){
        cin >> num[i];
    }
    int k;
    cin >> k;
    cout << SearchInBitonic(num, k);
    return 0;
}