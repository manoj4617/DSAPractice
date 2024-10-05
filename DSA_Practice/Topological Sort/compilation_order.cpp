#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/**
 * CompilationOrder takes a list of dependencies between nodes, and returns a valid
 * order in which the nodes can be compiled. The order is determined by doing a
 * topological sort of the nodes, which is a linear ordering of the nodes such that
 * for every edge (u,v), node u comes before v in the ordering. The algorithm
 * first builds an adjacency list of the nodes, and then iterates over the nodes
 * and their in-degrees, adding any nodes with in-degree 0 to a queue. It then
 * iterates over the queue, removing each node and adding it to the result list,
 * and then decreasing the in-degrees of each of its neighbors by 1. Any nodes
 * which now have an in-degree of 0 are added to the queue. This process is
 * repeated until the queue is empty.
 */
vector<char> CompilationOrder(vector<vector<char>>& dependencies){
    /**
     * adjList is an adjacency list, which is a map of nodes to a list of their
     * neighbors. The neighbors of a node are the nodes that the node has an
     * edge to.
     */
    map<char,vector<char>> adjList;
    /**
     * inDegrees is a map of nodes to their in-degrees. The in-degree of a node
     * is the number of edges that point to it.
     */
    map<char, int> inDegrees;
    /**
     * Iterate over the dependencies, and for each dependency, add the edge
     * to the adjacency list and increment the in-degree of the node that
     * the edge points to.
     */
    for(auto& depends : dependencies){
        char u = depends[1];
        char v = depends[0];

        adjList[u].push_back(v);
        inDegrees[v]++;
        /**
         * If the node u is not already in the inDegrees map, add it with an
         * in-degree of 0.
         */
        if(inDegrees.find(u) == inDegrees.end()){
            inDegrees[u] = 0;
        }
    }

    /**
     * result is the list of nodes in a valid order for compilation.
     */
    vector<char> result;

    /**
     * q is a queue of nodes to be processed. It is used to keep track of the
     * nodes that have an in-degree of 0, which are the nodes that can be
     * added to the result list.
     */
    deque<char> q;

    /**
     * Iterate over the inDegrees map, and add any nodes with an in-degree of
     * 0 to the queue.
     */
    for(auto& node : inDegrees){
        if(node.second == 0){
            q.push_back(node.first);
        }
    }

    /**
     * While the queue is not empty, remove the next node from the queue and
     * add it to the result list. Then, for each of its neighbors, decrement
     * their in-degree by 1, and if the in-degree of a neighbor becomes 0,
     * add it to the queue.
     */
    while(!q.empty()){
        char node = q.front();
        q.pop_front();
        result.push_back(node);
        for(char child : adjList[node]){
            inDegrees[child]--;
            if(inDegrees[child] == 0){
                q.push_back(child);
            }
        }
    }

    /**
     * Return the result list.
     */
    return result;
}

int main(){
    int n;
    // cin >> n;
    vector<vector<char>> dependencies = {
        {'c','a'},
        {'b','a'},
        {'d','c'},
        {'e','b'},
        {'e','d'}
    };

    vector<char> res = CompilationOrder(dependencies);
    for(char& c : res){
        cout << c << " ";
    }
    return 0;
}