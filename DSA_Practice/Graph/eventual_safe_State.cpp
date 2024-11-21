#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/**
 * Finds all safe nodes in a directed graph, which are nodes that lead to a terminal node (i.e., a node with no outgoing edges)
 * by reversing the edges and performing a topological sort.
 *
 * The idea of reversing the edges is to traverse the graph in reverse order, which means following the edges
 * in the opposite direction. This is done to identify nodes that do not have any incoming edges, which
 * means they are not dependent on any other nodes. These nodes are guaranteed to be safe, as they do not
 * have any dependencies.
 *
 * The algorithm works by first constructing the reverse graph and calculating the in-degrees of each node.
 * Then, it initializes a queue with all nodes that have zero in-degrees (i.e., no dependencies). It then
 * performs a topological sort by dequeuing nodes, marking them as safe, and reducing the in-degrees of their
 * neighbors. If a neighbor's in-degree becomes zero, it is enqueued. The process is repeated until the
 * queue is empty.
 *
 * Finally, the algorithm collects all safe nodes and returns them as a list.
 */
vector<int> eventualSafeSpace(vector<vector<int>>& graph) {
    int n = graph.size();  // Number of nodes in the graph
    
    // Initialize an adjacency list to store the reverse graph
    vector<vector<int>> adjList(n);
    
    // Initialize in-degrees for each node and a safe node status tracker
    vector<int> indegrees(n, 0);
    vector<bool> safe(n, false);

    // Construct the reverse graph and calculate in-degrees
    for (int i = 0; i < n; ++i) {
        for (int& node : graph[i]) {
            adjList[node].push_back(i);  // Reverse the direction of edges
            indegrees[i]++;  // Count incoming edges
        }
    }

    // Initialize a queue to perform a topological sort
    queue<int> q;
    
    // Enqueue all nodes with zero in-degree (i.e., no dependencies)
    for (int i = 0; i < n; ++i) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    // Perform the topological sort
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // Mark the node as safe
        safe[node] = true;

        // Reduce in-degrees of neighboring nodes
        for (int& neighbor : adjList[node]) {
            indegrees[neighbor]--;
            
            // If a neighbor node's in-degree becomes zero, enqueue it
            if (indegrees[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Collect all safe nodes
    vector<int> safenodes;
    for (int i = 0; i < n; ++i) {
        if (safe[i]) {
            safenodes.push_back(i);
        }
    }
    
    // Return the list of safe nodes
    return safenodes;
}

int main(){
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{0},{},{}};
    vector<int> res = eventualSafeSpace(graph);
    for(auto& i : res){
        cout << i << " ";
    }
    return 0;
}