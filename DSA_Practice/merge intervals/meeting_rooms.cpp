#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int s , int e) : start(s), end(e) {}
};

 /**
 * This function takes a vector of intervals and returns true if the intervals
 * can be attended, i.e. no two intervals overlap. Otherwise, it returns false.
 *
 * Algorithm:
 * 1. Sort the intervals by their start times.
 * 2. Iterate over the sorted intervals. If the start time of the current
 *    interval is less than the end time of the previous interval, return false.
 * 3. If the loop completes without finding any overlapping intervals, return true.
 */
bool canAttendMeetings(vector<Interval>& intervals) {
    /**
     * Sort the intervals by their start times. This is done to ensure that the
     * loop will find any overlapping intervals, since two overlapping intervals
     * will be next to each other after sorting.
     */
    sort(intervals.begin(), intervals.end(), [&](auto& x, auto& y){
        return x.start < y.start;
    }); 
    /**
     * Iterate over the sorted intervals. If the start time of the current
     * interval is less than the end time of the previous interval, return false.
     * This is because two overlapping intervals will have their start times
     * less than the end time of the previous interval.
     */
    for(int i=1;i<intervals.size();++i){
        if(intervals[i].start < intervals[i-1].end){
            return false;
        }
    }
    /**
     * If the loop completes without finding any overlapping intervals, return true.
     * This is because all the intervals can be attended without any conflicts.
     */
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<Interval> intervals(n, Interval(0,0));
    for(int i=0;i<n;++i){
        cin >> intervals[i].start >> intervals[i].end;
    }
    if(canAttendMeetings(intervals)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}