#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * This function finds the minimum eating rate that a monkey needs to finish
 * the given piles of bananas within the given time h. The function uses a
 * binary search algorithm to narrow down the search window of possible
 * eating rates until the eating rate that can finish the bananas within the
 * given time is found.
 *
 * The function takes a vector of integers representing the piles of bananas
 * and an integer h representing the time, and returns the minimum eating rate
 * as an integer.
 */
int minEatingRate(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int res = high;

    // Perform a binary search on the search window until the minimum eating
    // rate is found.
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long hours = 0;

        // Calculate the total time it takes to finish all the bananas with
        // the eating rate mid.
        for (int& pile : piles) {
            // The number of hours it takes to finish the pile of bananas is
            // the ceiling of the division of the pile size by the eating rate
            // mid.
            hours += (pile + mid - 1) / mid;
        }
        if (hours <= h) {
            // If the total time is less than or equal to the given time h,
            // then the eating rate mid can finish the bananas within the
            // given time, so the result is mid, and the search window is
            // narrowed to the left half.
            res = mid;
            high = mid - 1;
        }
        else {
            // Otherwise, the eating rate mid cannot finish the bananas within
            // the given time, so the search window is narrowed to the right
            // half.
            low = mid + 1;
        }
    }
    // Return the minimum eating rate that can finish the bananas within the
    // given time.
    return res;
}

int main(){

    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for(int i=0;i<n;++i){
        cin >> piles[i];
    }
    cout << minEatingRate(piles, h);
    return 0;
}