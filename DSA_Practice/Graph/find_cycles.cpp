#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int intersection(unordered_set<int>& set1, unordered_set<int>& set2){
    int count = 0;

    for(int s1 : set1){
        if(set2.find(s1) != set2.end()){
            count++;
        }
    }
    return count;
}

/**
 * Finds the number of cycles in a graph represented by the given
 * corridors. A cycle is two rooms that are connected to each other.
 *
 * @param n The number of rooms in the graph.
 * @param corridors A vector of vectors of two integers, each representing
 * a corridor between two rooms.
 * @return The number of cycles in the graph.
 */
int FindCycles(int n, const vector<vector<int>>& corridors){
    // Create a map from each room to a set of its neighbors
    unordered_map<int, unordered_set<int>> mp;
    int cycles = 0;

    // Iterate over all the corridors
    for(auto& c : corridors){
        int room1 = c[0];
        int room2 = c[1];

        // Add the neighbors to the map
        mp[room1].insert(room2);
        mp[room2].insert(room1);

        // Count the number of cycles in the graph
        cycles += intersection(mp[room1], mp[room2]);
    }

    return cycles;
}

int main(){
    vector<vector<int>> rooms = {{1,2},{5,2},{4,1},{2,4},{3,1},{3,4}};
    cout << FindCycles(5, rooms);
    return 0;
}