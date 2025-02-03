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

/**
 * This function takes in a vector of intervals, each represented as a vector of size 2.
 * It returns the minimum number of meeting rooms required to accomodate all the meetings.
 *
 * The main idea of the algorithm is to first sort the start times and end times of all
 * the intervals in two separate arrays. We then have two pointers, start and end, that
 * will iterate through the start and end times arrays respectively.
 *
 * We iterate through the start times array. If the start time of the current meeting
 * is less than the end time of the current meeting, then a new meeting has started, so
 * we increment the count of the number of meetings currently in progress. If the start
 * time of the current meeting is equal or greater than the end time of the current
 * meeting, then a meeting has ended, so we decrement the count of the number of
 * meetings currently in progress.
 *
 * At the end of the loop, the maximum count of the number of meetings currently in
 * progress is the minimum number of meeting rooms required to accomodate all the
 * meetings.
 */
int meeting_rooms(vector<vector<int>>& intervals){
    // get the start and end times in a separate array;
    int n = intervals.size();
    vector<int> startTimes;
    vector<int> endTimes;
    for(auto& times : intervals){
        startTimes.push_back(times[0]);
        endTimes.push_back(times[1]);
    }
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    int start = 0, end = 0;
    int res = 0, count = 0;

    while(start < n){
        // of start time is less than the end time it means a meeting has started
        // so increament the count
        if(startTimes[start] < endTimes[end]){
            start++;
            count++;
        }
        // if the start time is equal or greater than end time
        // it means a meeting has ended
        else{
            end++;
            count--;
        }
        res = max(res,count);
    }
    return res;
}

int main(){
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << meeting_rooms(intervals);

    return 0;
}