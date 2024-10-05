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
int find_peak(vector<int> &num){

    int start = 0;
    int end = num.size() - 1;

    while (start <= end) { // Loop until the search window is empty
        int mid = start + (end - start) / 2;

        // Check if we have found a peak element
        if ((mid == 0 || num[mid - 1] <= num[mid]) && 
            (mid == num.size() - 1 || num[mid] >= num[mid + 1])) {
            return num[mid];
        }

        // If the element at the midpoint is not a peak element, determine which side of the midpoint
        // contains the peak element
        if (mid > 0 && num[mid - 1] > num[mid]) { // Move towards the increasing side
            end = mid - 1;
        } else { 
            start = mid + 1; // Move towards the potentially increasing side
        }
    }
    return -1;
}

int main(){

    int n;
    cin >> n;
    
    vector<int> peak;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        peak.push_back(t);
    }

    cout << "peak: " << find_peak(peak) << endl;
    return 0;
}