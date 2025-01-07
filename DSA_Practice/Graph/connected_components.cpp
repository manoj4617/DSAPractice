#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>>& adj, int node, vector<bool>& visit){
    visit[node] = true;
    for(int n : adj[node]){
        if(!visit[n]){
            dfs(adj, n, visit);
        }
    }
}

void bfs(vector<vector<int>>& adj, int node, vector<bool>& visit){
    queue<int> q;
    q.push(node);
    visit[node] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int n : adj[node]){
            if(!visit[n]){
                visit[n] = true;
                q.push(n);
            }
        }
    }
}
/**
 * Counts the number of connected components in a graph with n nodes and a list of edges.
 *
 * @param n The number of nodes in the graph.
 * @param edges A list of edges, where each edge is a pair of two nodes.
 * @return The number of connected components in the graph.
 */
int countComponents(int n, vector<vector<int>>& edges) {
    // Create an adjacency list to store the graph
    vector<vector<int>> adj(n);
    // Create a boolean vector to keep track of visited nodes
    vector<bool> visit(n, false);

    // Iterate over all the edges and populate the adjacency list
    for(auto& e : edges){
        // Add each edge to the adjacency list in both directions
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // Initialize a result variable to count the number of connected components
    int res = 0;

    // Iterate over all the nodes in the graph and do a depth-first search (DFS)
    for(int node = 0;node < n;++node){
        // If a node has not been visited, do a DFS on the node and all its neighbors
        if(!visit[node]){
            // dfs(adj,node,visit);
            bfs(adj, node, visit);
            // Increment the result variable to count the number of connected components
            res++;
        }
    }

    // Return the result
    return res;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    cout << countComponents(n, edges) << endl;
    return 0;
}
