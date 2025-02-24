#include <iostream>
#include <vector>

using namespace std;

/**
 * Finds a peak element in the given array.
 * A peak element is an element that is greater than its neighbors.
 * If no peak element is found, the function returns -1.
 * 
 * The function works by using a binary search on the array. It keeps track of the start and end
 * indices of the current search window. At each iteration of the search, it calculates the midpoint
 * of the search window and checks if the element at the midpoint is a peak element. If it is, the
 * function returns the element as the peak element. If the element at the midpoint is not a peak
 * element, the function determines which side of the midpoint contains the peak element and narrows
 * the search window to that side. The function then repeats the search until the search window is
 * empty, at which point it returns -1 as the peak element.
 * 
 * @param num The array to search for a peak element.
 * @return The peak element if found, else -1.
 */
int Peak(const vector<int>& num){
    int low = 0;
    int high = num.size() - 1;

    // While the search window is not empty
    while(low <= high){
        // Calculate the midpoint of the current search window
        int mid = low + (high - low) / 2;

        // Check if we have found a peak element
        if((mid == 0 || num[mid - 1] <= num[mid]) && // mid is the first element or mid is greater than or equal to the element before it
            (mid == num.size() - 1 || num[mid] >= num[mid + 1])){ // mid is the last element or mid is greater than or equal to the element after it
            return num[mid];
        }

        // If the element at the midpoint is not a peak element, determine which side of the midpoint contains the peak element
        if(mid > 0 && num[mid - 1] > num[mid]){
            // If the element before the midpoint is greater than the element at the midpoint, the peak element must be in the left half of the search window
            high = mid - 1;
        }
        else{
            // If the element at the midpoint is not a peak element and the element before the midpoint is not greater than the element at the midpoint, the peak element must be in the right half of the search window
            low = mid + 1;
        }
    }
    // If the search window is empty, return -1 as the peak element
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i=0;i<n;++i){
        cin >> num[i];
    }
    cout << Peak(num);
    return 0;
}