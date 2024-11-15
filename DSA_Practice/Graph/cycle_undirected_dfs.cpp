#include <iostream>
#include <vector>

using namespace std;

/**
 * This is a depth-first search (DFS) function that takes the following parameters:
 * - `src`: The current node (vertex) in the graph.
 * - `adjList`: The adjacency list of the graph.
 * - `visited`: A boolean vector that keeps track of visited nodes.
 * - `parent`: The parent of the current node in the DFS traversal. It is set to -1
 *             if the node is the root of the DFS tree.
 *
 * The function performs a DFS traversal of the graph starting from the given node
 * and checks if a cycle is detected. If a cycle is detected, the function returns
 * `true`. Otherwise, it returns `false`.
 *
 * The function works by marking the current node as visited and then recursively
 * calling itself on all of its unvisited neighbors. If it encounters a node that
 * has already been visited and is not the parent of the current node, it means
 * that a cycle has been detected and the function returns `true`. Otherwise, the
 * function returns `false`.
 */
bool dfs(int src, vector<vector<int>>& adjList, vector<bool>& visited, int parent){
    // Mark the current node as visited
    visited[src] = true;

    // Iterate over all neighbors of the current node
    for(int nbr : adjList[src]){
        // If the neighbor has not been visited, recursively call the function on it
        if(!visited[nbr]){
            bool ans = dfs(nbr, adjList, visited, src);
            // If the recursive call detects a cycle, return true
            if(ans)
                return true;
        }
        // If the neighbor has been visited and is not the parent of the current node,
        // it means that a cycle has been detected and the function returns true
        else if(visited[nbr] && nbr != parent){
            return true;
        }
    }
    // If no cycle is detected, return false
    return false;
}


bool DetectCycle(int n, vector<vector<int>> adj){
    vector<bool> visited(n);

    for(int i=0;i<n;++i){
        if(!visited[i]){
            bool ans = dfs(i, adj, visited, -1);
            if(ans == true)
                return true;
        }
    }
    return false;
}

int main(){
    int V = 3;
    vector<vector<int>> adj(V);

    adj[1].push_back(0);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);

    DetectCycle(V, adj) ? cout << "Contains cycle\n"
                     : cout << "No Cycle\n";

    V = 3;
    vector<vector<int>> adj2(V);

    adj2[0].push_back(1);
    adj2[1].push_back(0);
    adj2[1].push_back(2);
    adj2[2].push_back(1);

    DetectCycle(V, adj2) ? cout << "Contains Cycle\n"
                      : cout << "No Cycle\n";

    return 0;
}