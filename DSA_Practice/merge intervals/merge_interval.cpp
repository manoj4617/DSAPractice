#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> MergeIntervals(std::vector<std::vector<int>> &intervals)
{
    // This function takes in a vector of intervals, each represented as a vector of size 2,
    // where the first element is the start of the interval and the second element is the end.
    // The function merges overlapping intervals and returns the merged intervals in a new vector.
    //
    // For example:
    // If the input is {{1, 3}, {2, 6}, {8, 10}, {15, 18}}
    // the output will be {{1, 6}, {8, 10}, {15, 18}}
    //
    // The main idea of the algorithm is to keep track of the last merged interval and compare it with
    // the current interval. If the current interval overlaps with the last merged interval, we merge them
    // into a single interval and add it to the result. Otherwise, we simply add the current interval to the
    // result.
    //
    // The function starts by initializing an empty result vector and adding the first interval to it.

    std::vector<std::vector<int>> result;

    result.push_back({intervals[0][0], intervals[0][1]});

    // Then, it iterates over the rest of the intervals
    for(int i=1;i<intervals.size();i++){

        // We get the start and end of the current interval being processed
        int curStart = intervals[i][0];
        int curEnd = intervals[i][1];

        // We get a reference to the last merged interval in the result
        std::vector<int> lastInterval = result.back();

        // We get the end of the last merged interval
        int prevEnd = lastInterval[1];

        // If the current interval overlaps with the last merged interval,
        if(curEnd <= prevEnd){

            // we merge them into a single interval by taking the max of their ends
            lastInterval[1] = std::max(curEnd, prevEnd);

            // We remove the last merged interval from the result
            result.pop_back();

            // And we add the new merged interval to the result
            result.push_back(lastInterval);

        }
        else{

            // If the current interval does not overlap with the last merged interval,
            // we simply add it to the result
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