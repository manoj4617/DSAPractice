#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

/**
 * This function takes in a vector of intervals, each represented as a vector of size 2.
 * It returns the minimum number of meeting rooms required to accomodate all the meetings.
 *
 * The main idea of the algorithm is to first sort the intervals by their start times.
 * We then use a priority queue to keep track of the end times of all the meeting rooms.
 * We iterate through the sorted intervals. If the start time of the current interval is
 * greater than or equal to the top of the priority queue, then the current meeting can
 * be accomodated in one of the existing meeting rooms, so we remove the top of the
 * priority queue and add the end time of the current meeting to the priority queue.
 * If the start time of the current meeting is less than the top of the priority queue,
 * then we add the end time of the current meeting to the priority queue, which will
 * require a new meeting room.
 *
 * At the end of the loop, the size of the priority queue is the minimum number of
 * meeting rooms required to accomodate all the meetings.
 */
int minMeetingRooms(vector<vector<int>>& intervals){
    /**
     * Sort the intervals by their start times
     */
    sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        }
    );
    /**
     * min_heap is a priority queue that will keep track of the end times of all the meeting rooms
     */
    priority_queue<int,vector<int>, greater<int>> min_heap;
    /**
     * Iterate through the sorted intervals
     */
    for(int i=0;i<intervals.size();++i){
        /**
         * If the start time of the current interval is greater than or equal to the top of the
         * priority queue, then the current meeting can be accomodated in one of the existing
         * meeting rooms, so we remove the top of the priority queue and add the end time of the
         * current meeting to the priority queue.
         */
        if(min_heap.size() > 0 && min_heap.top() <= intervals[i][0]){
            min_heap.pop();
        }
        /**
         * Add the end time of the current meeting to the priority queue
         */
        min_heap.push(intervals[i][1]);
    }

    /**
     * At the end of the loop, the size of the priority queue is the minimum number of
     * meeting rooms required to accomodate all the meetings.
     */
    return min_heap.size();
}

int main(){
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << minMeetingRooms(intervals);

    return 0;
}