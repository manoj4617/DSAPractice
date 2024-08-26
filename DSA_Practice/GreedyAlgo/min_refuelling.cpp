#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief This function takes a target distance, the starting fuel, and a set of fueling stations
 *        and returns the minimum number of stops required to reach the target distance.
 *
 * The algorithm works by iterating through the stations and keeping track of the maximum
 * distance we can travel with the current fuel and the stops we've made so far. If we can't
 * reach the target distance with the current fuel, we add the maximum fuel we can get from
 * the current station to the heap and increment the stops counter.
 *
 * If we can reach the target distance with the current fuel, we return the number of stops
 * we've made.
 *
 * @param target the target distance
 * @param startFuel the starting fuel
 * @param stations the set of fueling stations
 * @return the minimum number of stops required to reach the target distance
 */
int MinRefuelling(int target, int startFuel, vector<vector<int>>& stations){

    if(startFuel >= target){
        return 0;
    }

    // The maximum distance we can travel with the current fuel
    int maxDist = startFuel;

    // A priority queue to store the maximum fuel we can get from the current station
    priority_queue<int> maxHeap;

    // The number of stations we've visited so far
    int i = 0;

    // The number of stops we've made so far
    int stops = 0;

    // Iterate through the stations until we can reach the target distance with the current fuel
    while(maxDist < target){
        // If we can reach the current station with the current fuel, add the maximum fuel
        // we can get from the current station to the heap and increment the stops counter
        if(i < stations.size() && stations[i][0] <= maxDist){
            maxHeap.push(stations[i][1]);
            i++;
        }
        // If we can't reach the current station with the current fuel, return -1
        else if(maxHeap.empty()){
            return -1;
        }
        // Otherwise, add the maximum fuel we can get from the heap to the current fuel
        // and increment the stops counter
        else {
            maxDist += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
    }

    // Return the number of stops we've made
    return stops;
}


int main(){

    int n, startFuel, target;
    cin >> n >> startFuel >> target;
    vector<vector<int>> stations(n);
    for(int i=0;i<n;++i){
        int dist;
        int fuel;
        cin >> dist >> fuel;
        stations.push_back({dist,fuel});
    }
    cout << MinRefuelling(target, startFuel, stations);
}