#include<iostream>
#include <cassert>

using namespace std;

/**
 * @brief This function finds the equilibrium point in an array 'a' of length 'n'.
 * An equilibrium point is an index in the array where the sum of elements to the left
 * is equal to the sum of elements to the right.
 *
 * @param a The input array
 * @param n The length of the input array
 * @return The index of the equilibrium point if it exists, -1 otherwise
 */
int findEqui(long long a[], int n){
    // Base case: if the array is empty or has only one element, there is no equilibrium point
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    // Initialize the sum of elements to the left and right of the middle point
    int rsum = 0, lsum = 0;
    
    // Calculate the sum of elements to the left and right of the middle point
    // Note: we are assuming that the array is sorted
    for(int i=0;i<n/2;++i){
        lsum += a[i];
    }
    for(int j=n-1;j>n/2;--j){
        rsum += a[j];
    }

    // Initialize pointers to the left and right of the middle point
    int mid = n/2;
    int left = mid - 1;
    int right = mid + 1;

    // Start the sliding window approach
    while(left != 0 || right!= 0){
        // If the sum of elements to the left is equal to the sum of elements to the right,
        // an equilibrium point has been found
        if(lsum == rsum)
            return left+1; 
        else{
            // If the sum of elements to the left is greater than the sum of elements to the right,
            // slide the window to the left
            if(lsum > rsum){
                lsum -= a[left];
                rsum += a[mid];
                mid = left;
                left--;
                right--;
            }
            // If the sum of elements to the left is less than the sum of elements to the right,
            // slide the window to the right
            else if(lsum < rsum){
                rsum -= a[right];
                lsum += a[mid];
                mid = right;
                right++;
                left++;
            }
        }
    }
    // If no equilibrium point is found, return -1
    return -1;
}

int main(){
    // int n;
    // cin >> n;
    // long long a[n];

    // for(int i=0;i<n;++i){
    //     cin >> a[i];
    // }

    // cout << findEqui(a,n) << endl;
    // return 0;


    // Test case 1: Empty array
    {
        long long a[] = {};
        int n = 0;
        assert(findEqui(a, n) == 0);
    }

    // Test case 2: Array with one element
    {
        long long a[] = {1};
        int n = 1;
        assert(findEqui(a, n) == 1);
    }

    // Test case 3: Array with equilibrium point at the beginning
    {
        long long a[] = {1, 2, 3, 4, 5};
        int n = 5;
        assert(findEqui(a, n) == 0);
    }

    // Test case 4: Array with equilibrium point at the end
    {
        long long a[] = {1, 2, 3, 4, 5};
        int n = 5;
        assert(findEqui(a, n) == 4);
    }

    // Test case 5: Array with equilibrium point in the middle
    {
        long long a[] = {1, 2, 3, 4, 5};
        int n = 5;
        assert(findEqui(a, n) == 2);
    }

    // Test case 6: Array with no equilibrium point
    {
        long long a[] = {1, 2, 3, 4, 5};
        int n = 5;
        assert(findEqui(a, n) == -1);
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}