#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes in a number of courses (n), a list of courses that have prerequisites (courses),
 * and a list of queries to check if a course is a prerequisite of another course (queries).
 * It returns a boolean list indicating whether the course in the first index of each query is a
 * prerequisite of the course in the second index of each query.
 *
 * @param n The number of courses.
 * @param courses A 2D vector of integers representing the courses that have prerequisites.
 *        courses[i][0] is the prerequisite course and courses[i][1] is the course that has the prerequisite.
 * @param queries A 2D vector of integers representing the queries to check.
 *        queries[i][0] is the course to check if it is a prerequisite of the course in queries[i][1].
 *
 * @return A boolean list indicating whether the course in the first index of each query is a
 *         prerequisite of the course in the second index of each query.
 */
vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& courses, vector<vector<int>>& queries){
    /**
     * Initialize a 2D vector of booleans to keep track of which courses are prerequisites of which
     * courses. The value at isReachable[i][j] is true if course i is a prerequisite of course j.
     */
    vector<vector<bool>> isReachable(n,vector<bool>(n,false));

    /**
     * Initialize a vector to store the result of the queries.
     */
    vector<bool> result;

    /**
     * Iterate over the courses and mark the prerequisites as true in the isReachable matrix.
     */
    for(const auto& c : courses){
        isReachable[c[0]][c[1]] = true;
    }

    /** Floyd-Warshall Algorithm 
     * Iterate over the isReachable matrix and perform a transitive closure operation to
     * propagate the prerequisites to all reachable courses.
     */
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                /** checking transitivity
                 * If course i is a prerequisite of course k, and course k is a prerequisite of course j,
                 * then course i is a prerequisite of course j.
                 */
                isReachable[i][j] = isReachable[i][j] || (isReachable[i][k] && isReachable[k][j]);
            }
        }
    }

    /**
     * Iterate over the queries and check if the course in the first index of each query is a
     * prerequisite of the course in the second index of each query.
     */
    for(const auto& q : queries){
        result.push_back(isReachable[q[0]][q[1]]);
    }
    return result;
}

int main(){
    int n = 5;
    vector<vector<int>> courses = {{0,1},{1,2},{3,4},{0,4}};
    vector<vector<int>> queries = {{0,4},{4,2}};

    vector<bool> res = checkIfPrerequisite(n, courses, queries);
    for(int i=0;i<res.size();++i){
        cout << i <<  ": " << res[i] << "\n";
    }
    return 0;
}