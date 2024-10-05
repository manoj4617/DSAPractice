#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * Determines if a valid order exists to take a list of courses such that all
 * prerequisites are satisfied.
 *
 * @param courses A list of courses, where each course is represented as a
 * vector of two elements, the first element being the course number and the
 * second element being the course number that the course depends on.
 * @param n The number of courses.
 * @return True if a valid order exists, else false.
 */
bool course_schedule(vector<vector<int>> &courses, int n){
    /**
     * adjList is an adjacency list, which is a map of nodes to a list of their
     * neighbors. The neighbors of a node are the nodes that the node has an
     * edge to.
     */
    unordered_map<int,vector<int>> adjList;
    /**
     * inDegrees is a map of nodes to their in-degrees. The in-degree of a node
     * is the number of edges that point to it.
     */
    unordered_map<int,int> inDegrees;
    int counter = 0;
    /**
     * Iterate over the courses, and for each course, add the edge to the
     * adjacency list and increment the in-degree of the node that the edge
     * points to.
     */
    for(auto& course : courses){
        int courseNum = course[0];
        int dependsOn = course[1];
        adjList[dependsOn].push_back(courseNum);
        inDegrees[courseNum]++;
        /**
         * If the node that the edge points to is not already in the inDegrees
         * map, add it with an in-degree of 0.
         */
        if(inDegrees.find(dependsOn) == inDegrees.end()){
            inDegrees[dependsOn] = 0;
        }
    }

    /**
     * Create a queue and add all nodes with in-degree 0 to it. The queue will
     * be used to keep track of the nodes that have no dependencies.
     */
    queue<int> dq;
    for(auto& degrees : inDegrees){
        if(degrees.second == 0){
            dq.push(degrees.first);
        }
    }

    /**
     * result is the list of nodes in a valid order for taking the courses.
     */
    vector<int> res;

    /**
     * Iterate over the queue and add the nodes to the result list. For each
     * node, decrement the in-degrees of all its neighbors, and if a node has an
     * in-degree of 0 after the decrement, add it to the queue.
     */
    while(!dq.empty()){
        int node = dq.front();
        res.push_back(node);
        dq.pop();
        counter++;
        for(auto& n : adjList[node]){
            inDegrees[n]--;
            if(inDegrees[n] == 0){
                dq.push(n);
            }
        }
    }

    /**
     * Return true if all nodes were visited, and false otherwise.
     */
    return counter == n;

}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> courses = {
        {1,0},
        {2,0},
        {3,1},
        {4,3}
    };
    cout << course_schedule(courses,n);
    return 0;
}