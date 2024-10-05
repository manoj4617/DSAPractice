#include <iostream>

using namespace std;

/**
 * This function searches for a given value in an infinite sorted array.
 * It assumes that the array is infinite, and therefore does not check for
 * out of bounds conditions.
 * @param arr The array to search.
 * @param k The value to search for.
 * @return The index of k in the array, or -1 if k is not found.
 */
int FindInInfiniteArray(int arr[], int k){
    // Set the low and high pointers to the first and second elements of the array.
    int low = 0;
    int high = 1;

    // Expand the search window until the value at the high pointer is greater than or equal to k.
    // This is done by repeatedly multiplying the high pointer by 2, until the value at the high
    // pointer is greater than or equal to k.
    while(arr[high] < k){
        // Set the low pointer to the current high pointer.
        low = high;
        // Multiply the high pointer by 2 to expand the search window.
        high *= 2;
    }

    // Perform a binary search in the search window established above.
    while(low <= high){
        // Calculate the midpoint of the current search window.
        int mid = low + (high - low) / 2;
        // Check if the value at the midpoint is equal to k.
        if(arr[mid] == k){
            // If the value at the midpoint is equal to k, return its index.
            return mid;
        }
        // If the value at the midpoint is greater than k, then k must be in the left half of the search window.
        if(arr[mid] > k){
            // Set the high pointer to the midpoint - 1 to narrow the search window.
            high = mid - 1;
        }
        // If the value at the midpoint is less than k, then k must be in the right half of the search window.
        else if(arr[mid] < k){
            // Set the low pointer to the midpoint + 1 to narrow the search window.
            low = mid + 1;
        }
    }
    // If the search window is empty, then k is not in the array.
    return -1;
}

/**
 * The time complexity of this algorithm is O(log(k)), since the search window is expanded
 * exponentially until the value at the high pointer is greater than or equal to k, and then
 * the search window is narrowed by half in each iteration of the binary search.
 */

int main(){
    int arr[1000];
    int n,i=0;
    while(n != -1){
        cin >> n;
        arr[i] = n;
        i++;
    }
    int k;
    cin >> k;
    cout << FindInInfiniteArray(arr,k);
    return 0;
}