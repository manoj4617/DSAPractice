#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * This function takes in a vector of intervals, each represented as a vector of size 2.
 * The function returns a new vector of merged intervals, where overlapping intervals are merged
 * into a single interval.
 *
 * The idea of the algorithm is to first sort the intervals by their start times.
 * Then, we iterate through the sorted intervals. For each interval, we check if it overlaps with
 * the last interval in the result vector. If it does, we merge the two intervals by updating the
 * end time of the last interval in the result vector to be the maximum of its current end time
 * and the end time of the current interval. If it does not overlap, we add it to the result vector.
 *
 */
std::vector<std::vector<int>> MergeIntervals(std::vector<std::vector<int>> &intervals)
{
        // Sort the intervals by their start times
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>& a, const vector<int>& b)-> bool{
            // Compare the start times of the two intervals
            return a[0] < b[0];
        });

        // Initialize the result vector with the first interval
        vector<vector<int>> result;
        result.push_back({intervals[0][0], intervals[0][1]});

        // Iterate through the intervals starting from the second interval
        for(int i = 1; i < intervals.size(); i++){
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];

            // Get the last interval in t he result vector
            vector<int> lastInterval = result.back();
            int prvEnd = lastInterval[1];

            // Check if the current interval overlaps with the last interval in the result vector
            if(curStart <= prvEnd){
                // Merge the two intervals by updating the end time of the last interval
                lastInterval[1] = max(curEnd, prvEnd);
                // Remove the last interval from the result vector and add the merged interval back
                result.pop_back();
                result.push_back(lastInterval);
            }
            else{
                // Add the current interval to the result vector
                result.push_back({curStart, curEnd});
            }
        }
        return result;
}

int main(){

    std::vector<std::vector<int>> intervals = {{1, 5}, {4, 6}, {6, 8}, {11, 15}};
    std::vector<std::vector<int>> result = MergeIntervals(intervals);

    for(int i=0;i<result.size();i++){
        std::cout << "{" << result[i][0] << "," << result[i][1] << "} " << " ";
    }

    return 0;
}