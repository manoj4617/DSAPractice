#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> adj;
    vector<int> bfs(int startNode, int len){
        queue<pair<int,int>> q;
        vector<bool> visit(len, false);

        visit[startNode] = true;
        q.push({startNode, 0});
        vector<int> dist(len, -1);
        dist[startNode] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            for(int nei : adj[node]){
                if(!visit[nei]){
                    q.push({nei, distance + 1});
                    visit[nei] = true;
                    dist[nei] = distance + 1;
                }
            }
        }

        return dist;
    }
    /**
     * Finds the node closest to both node1 and node2 in the graph represented
     * by the given edges. The graph is represented as a vector of integers,
     * where each integer is the index of the node's neighbor in the graph.
     * If a node has no neighbor, its value is -1.
     *
     * The function first builds the adjacency list of the graph, and then
     * performs two breadth-first searches (BFS) starting from node1 and node2
     * respectively. The BFS is used to find the shortest distance from each
     * node to both node1 and node2.
     *
     * Then, the function iterates over all nodes in the graph and finds the
     * node with the minimum maximum distance to both node1 and node2. If
     * multiple nodes have the same minimum maximum distance, the function
     * returns the node with the smallest index.
     *
     * @param edges A vector of integers representing the graph.
     * @param node1 The first node.
     * @param node2 The second node.
     * @return The node closest to both node1 and node2 in the graph.
     */
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int len = edges.size();
        adj.resize(len);
        for (int i = 0; i < len; ++i) {
            // If the node has a neighbor, add the neighbor to the adjacency list
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        // Perform a breadth-first search starting from node1
        vector<int> fromNode1 = bfs(node1, len);
        // Perform a breadth-first search starting from node2
        vector<int> fromNode2 = bfs(node2, len);

        // Initialize the minimum maximum distance and the result node
        int minDist = INT_MAX;
        int res = -1;

        // Iterate over all nodes in the graph
        for (int i = 0; i < len; ++i) {
            // If the node has a distance to both node1 and node2
            if (fromNode1[i] != -1 && fromNode2[i] != -1) {
                // Calculate the maximum distance to both node1 and node2
                int maxDist = max(fromNode1[i], fromNode2[i]);

                // If the maximum distance is smaller than the current minimum
                // maximum distance, or if the maximum distance is equal and the
                // current node has a smaller index, update the result
                if (maxDist < minDist || (maxDist == minDist && i < res)) {
                    minDist = maxDist;
                    res = i;
                }
            }
        }

        // Return the result node
        return res;
    }

int main(){
    vector<int> edges = {1,2,3,4,5,-1,6,7,-1,8,-1,9,-1,10};
    cout << closestMeetingNode(edges, 1, 10) << endl;
    return 0;
}