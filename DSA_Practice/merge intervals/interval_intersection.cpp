#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
* This function takes two list of intervals, and returns 
* the list of intervals that are common to both of them.
*
* @param intervalListA: the first list of intervals
* @param intervalListB: the second list of intervals
* @return: the list of intervals that are common to both A and B
*/
vector<vector<int>> IntervalsIntersection(vector<vector<int>> intervalListA, vector<vector<int>> intervalListB)
{
    /**
     * The variable dummyResult is used to store the result of the function
     */
    vector<vector<int>> dummyResult;
    
    /**
     * i and j are used as indices to iterate through the two intervals lists.
     * They are initialized to 0.
     */
    int i=0,j=0;
    
    /**
     * len_a and len_b are the lengths of intervalListA and intervalListB respectively.
     * They are used to terminate the loops.
     */
    int len_a = intervalListA.size();
    int len_b = intervalListB.size();

    /**
     * The while loop iterates until i >= len_a or j >= len_b.
     * At each iteration, the loop does the following:
     * 1. It creates an empty vector called temp, which will be used to store the current interval.
     * 2. It calculates the start and end points of the new interval
     *    by taking the maximum of the start points of intervalA[i] and intervalB[j],
     *    and the minimum of the end points of intervalA[i] and intervalB[j].
     * 3. If the new interval is not empty (i.e the start point is less than or equal to the end point),
     *    then it adds the new interval to the result.
     * 4. If the end point of intervalA[i] is less than the end point of intervalB[j],
     *    then it increments i, otherwise it increments j.
     */
    while(i < len_a && j < len_b){
        std::vector<int> temp;

        int new_interval_start = std::max(intervalListA[i][0], intervalListB[j][0]);
        int new_interval_end = std::min(intervalListA[i][1], intervalListB[j][1]);
        if(new_interval_start <= new_interval_end){
            temp.push_back(new_interval_start);
            temp.push_back(new_interval_end);
            dummyResult.push_back(temp);
        }

        if(intervalListA[i][1] < intervalListB[j][1]){
            i++;
        }
        else{
            j++;
        }
    }

    /**
     * Finally, the function returns the result, which is the list of intervals
     * that are common to both A and B.
     */
    return dummyResult; 
}
