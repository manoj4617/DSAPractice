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
    if (k <= 0 || points.empty())
    {
        return {};
    }

    // Create a priority queue to store the points and their distances from the origin
    priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>>> pq;

    // Initialize the priority queue with the first k points from the points vector
    for (int i = 0; i < min(k, static_cast<int>(points.size())); i++)
    {
        // Calculate the distance between each point and the origin
        float d = calculate_size(points[i][0], points[i][1]);
        // Add the point and its distance to the priority queue
        pq.push({d, {points[i][0], points[i][1]}});
    }

    // While the size of the priority queue is less than k and there are still points in the points vector
    while (k--)
    {
        // Remove the first point from the points vector
        points.erase(points.begin());
        // If there are still points in the points vector
        if (!points.empty())
        {
            // Calculate the distance between the first point and the origin
            float dist = calculate_size(points[0][0], points[0][1]);
            // If the distance is less than the distance of the closest point in the priority queue
            if (dist < pq.top().first)
            {
                // Remove the closest point from the priority queue
                pq.pop();
                // Add the new point and its distance to the priority queue
                pq.push({dist, {points[0][0], points[0][1]}});
            }
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
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> res = KthNearest(points, k);
    for(int i=0;i<res.size();i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}