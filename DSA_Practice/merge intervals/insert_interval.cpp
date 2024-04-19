#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// This function takes in two intervals vectors, existingIntervals and newInterval.
// It returns a new vector of intervals that contains all the intervals from
// existingIntervals and newInterval, after merging the overlapping intervals.
//
// The idea is to iterate through existingIntervals and newInterval in sorted
// order. We maintain a result vector of intervals and keep adding intervals
// to it, without overlapping. If we encounter an interval that overlaps with
// the previously added interval, we merge them, else we add the new interval
// to the result vector.
//
// For example, if existingIntervals is [ [1, 3], [5, 7] ] and newInterval is
// [2, 6], the result returned should be [ [1, 7] ].
//
vector<vector<int>> InsertInterval(vector<vector<int>> existingIntervals, vector<int> newInterval)
{
    // If existingIntervals is empty, there's nothing to merge, so we return a
    // vector with only the newInterval.
    if(existingIntervals.empty()){
        return vector<vector<int>>{newInterval};
    }

    // size will be the number of intervals in existingIntervals. i will be the
    // index of the current interval being processed.
    int size = existingIntervals.size(), i = 0;
    // res is the result vector of intervals. We will add intervals to it after
    // processing them.
    vector<vector<int>> res = {};

    // newend and newstart will be used to keep track of the end and start of
    // newInterval.
    int newend = newInterval[1];
    int newstart = newInterval[0];

    // We iterate through existingIntervals until i reaches size or an interval
    // in existingIntervals has an end time that is greater than the start time
    // of newInterval.
    while(i < size && newstart > existingIntervals[i][0]){
        // We add the current interval in existingIntervals to res without
        // overlapping.
        res.push_back(existingIntervals[i]);
        i++;
    }

    // If res is empty or the last interval in res has an end time that is less
    // than the start time of newInterval, we add newInterval to res. Else,
    // we merge newInterval with the last interval in res.
    if(res.empty() || res.back()[1] < newstart){
        res.push_back(newInterval);
    }
    else{
        // We update the end time of the last interval in res to be the maximum
        // of its current end time and the end time of newInterval.
        res.back()[1] = std::max(res.back()[1], newend);
    }

    // We continue iterating through existingIntervals until i reaches size.
    while(i < size){
        // We get the current interval in existingIntervals.
        vector<int> ei = existingIntervals[i];
        // We get the start and end times of the current interval.
        int start = ei[0], end = ei[1];
        // If the last interval in res has an end time that is less than the
        // start time of the current interval, we add the current interval to
        // res. Else, we merge the current interval with the last interval in
        // res.
        if(res.back()[1] < start){
            res.push_back(ei);
        }
        else{
            // We update the end time of the last interval in res to be the
            // maximum of its current end time and the end time of the current
            // interval.
            res.back()[1] = std::max(res.back()[1], end);
        }
        i++;
    }

    // We return the merged intervals in res.
    return res;
}
