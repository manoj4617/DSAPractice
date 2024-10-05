#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * Given a list of courses, returns a valid order in which the courses can be taken.
 * The order is determined by doing a topological sort of the courses, which is a
 * linear ordering of the courses such that for every edge (u,v), course u comes
 * before v in the ordering.
 *
 * @param courses A list of courses, where each course is represented as a
 * vector of two elements, the first element being the course number and the
 * second element being the course number that the course depends on.
 * @param n The number of courses.
 * @return A list of courses in a valid order.
 */
vector<int> course_schedule_2(vector<vector<int>> &courses, int n){
    // Create adjacency list and in-degrees map
    // The adjacency list maps each course to a list of courses that it depends on.
    // The in-degrees map maps each course to its in-degree, which is the number of
    // courses that it depends on.
    unordered_map<int,vector<int>> adjList;
    unordered_map<int,int> inDegrees;

    // Iterate over the courses and build the adjacency list and in-degrees map
    for(auto& course : courses){
        int courseNum = course[0];
        int dependsOn = course[1];
        adjList[dependsOn].push_back(courseNum);
        inDegrees[courseNum]++;
        if(inDegrees.find(dependsOn) == inDegrees.end()){
            inDegrees[dependsOn] = 0;
        }
    }

    // Create a queue and add all courses with in-degree 0 to it
    // The queue will be used to keep track of the courses that have no dependencies
    queue<int> dq;
    for(auto& degrees : inDegrees){
        if(degrees.second == 0){
            dq.push(degrees.first);
        }
    }

    // Create a result list to store the valid order of courses
    vector<int> res;

    // Iterate over the queue and add the courses to the result list
    while(!dq.empty()){
        // Pop the front of the queue and add it to the result list
        int node = dq.front();
        res.push_back(node);
        dq.pop();

        // Iterate over the adjacency list and decrement the in-degree of each
        // course that the popped course depends on
        // If the in-degree of a course is 0, add it to the queue
        for(auto& n : adjList[node]){
            inDegrees[n]--;
            if(inDegrees[n] == 0){
                dq.push(n);
            }
        }
    }

    // Return the result list
    return res;

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
    vector<int> res = course_schedule_2(courses,n);
    for(int& r : res){
        cout << r << " ";
    }
    return 0;
}