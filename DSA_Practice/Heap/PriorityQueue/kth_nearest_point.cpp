#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

float calculate_size(int p, int q){
    return sqrt(p*p + q*q);
}

/*
    This function takes a 2D vector of points and an integer k. It returns a 2D vector containing the k points
    from the original vector that are closest to the origin (0,0). The function uses a priority queue to keep
    track of the k points closest to the origin. The priority queue is sorted in descending order based on the
    distance between each point and the origin.

    Parameters:
        - points: A 2D vector of integers representing the points
        - k: An integer representing the number of points to return

    Return:
        - A 2D vector of integers containing the k points from the original vector that are closest to the origin
*/
vector<vector<int>> KthNearest(vector<vector<int>> points, int k)
{
    // If k is less than or equal to 0 or the points vector is empty, return an empty vector
    int i;
    if (k <= 0 || points.empty())
    {
        return {{}};
    }

    // Create a priority queue to store the points and their distances from the origin
    priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>> pq;

    for(auto& point : points){
        pq.push({calculate_size(point[0], point[1]), {point[0], point[1]}});
        // If the priority queue size exceeds k, remove the furthest point from the priority queue
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    // Create a vector to store the final result
    vector<vector<int>> res(pq.size());
    // While there are still points in the priority queue
    while (!pq.empty())
    {
        // Add the point and its distance to the result vector
        res.push_back({pq.top().second.first, pq.top().second.second});
        // Remove the point from the priority queue
        pq.pop();
    }

    // Return the result vector
    return res;
}

int main(){
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {0,1},{1,1}};
    int k = 2;
    vector<vector<int>> res = KthNearest(points, k);
    for(int i=0;i<res.size();i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}