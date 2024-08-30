#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/**
 * This function takes in a vector of intervals, each represented as a vector of size 2.
 * The function returns the number of intervals that need to be removed in order to
 * not have any overlapping intervals.
 *
 * The main idea of the algorithm is to first sort the intervals by their end times.
 * Then, we keep track of the end time of the last interval we have seen. If the start
 * time of the current interval is greater than the end time of the last interval, we
 * know that the current interval does not overlap with the last interval, so we update
 * the end time of the last interval to be the end time of the current interval and
 * increment the count of the number of intervals that do not overlap with the last
 * interval.
 *
 * If the start time of the current interval is not greater than the end time of the
 * last interval, then the current interval overlaps with the last interval, so we
 * increment the count of the number of intervals that need to be removed.
 *
 * The function returns the count of the number of intervals that need to be removed.
 */
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    /**
     * Sort the intervals by their end times
     */
    sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

    /**
     * Initialize the end time of the last interval to be the end time of the first interval
     * and the count of the number of intervals that need to be removed to be 0.
     */
    int curend = intervals[0][1];
    int count = 0;

    /**
     * Iterate over the intervals starting from the second interval
     */
    for(int i=1;i<intervals.size();++i){
        /**
         * If the start time of the current interval is not greater than the end time of the
         * last interval, then the current interval overlaps with the last interval, so
         * increment the count of the number of intervals that need to be removed.
         */
        if(curend > intervals[i][0]){
            count++;
        }
        else{
            /**
             * If the start time of the current interval is greater than the end time of the
             * last interval, then the current interval does not overlap with the last
             * interval, so update the end time of the last interval to be the end time of
             * the current interval and increment the count of the number of intervals that
             * do not overlap with the last interval.
             */
            curend = intervals[i][1];
        }
    }

    /**
     * Return the count of the number of intervals that need to be removed.
     */
    return count;
}

int main(){
    vector<vector<int>> interval = {
        {1,2},{2,3},{3,4},{1,3}
    };
    cout << eraseOverlapIntervals(interval);
}