#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int NetworkTimeDelay(vector<vector<int>>& times, int n, int k) {
    // Create an adjacency list to represent the graph. Each node points to a list of pairs,
    // where each pair contains a neighbor node and the time delay to reach that neighbor.
    vector<vector<pair<int, int>>> adjList(n);

    // Min-heap priority queue to store and retrieve the next node with the smallest delay time.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Set to keep track of visited nodes.
    unordered_set<int> visited(n);

    // Start the process with the source node 'k' and an initial delay of 0.
    pq.push({0, k});

    // Populate the adjacency list using the given 'times' information.
    for (auto& item : times) {
        adjList[item[0]].push_back({item[1], item[2]});
    }
    
    // Variable to track the maximum delay time encountered during the process.
    int delays = 0;

    // Loop until there are no more nodes to process in the priority queue.
    while (!pq.empty()) {
        // Retrieve the node with the smallest delay time.
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If this node has already been visited, skip further processing.
        if (visited.count(node)) {
            continue;
        }

        // Mark the node as visited.
        visited.insert(node);

        // Update the maximum delay time.
        delays = std::max(time, delays);

        // Retrieve the neighbors of the current node from the adjacency list.
        vector<pair<int, int>>& neighbors = adjList[node];

        // Iterate over each neighbor.
        for (auto& neighbor : neighbors) {
            int n_node = neighbor.first;  // Neighbor node
            int n_delay = neighbor.second; // Delay to reach the neighbor

            // If the neighbor has not been visited, calculate the new delay time and add it to the queue.
            if (!visited.count(n_node)) {
                int newTime = time + n_delay;
                pq.push({newTime, n_node});
            }
        }
    }

    // Check if all nodes have been visited by comparing the size of the visited set with the total number of nodes.
    // If all nodes are visited, return the maximum delay time; otherwise, return -1 indicating not all nodes were reached.
    if (visited.size() == n) {
        return delays;
    }
    return -1;
}


int main() {
    std::vector<std::vector<std::vector<int>>> times = {
        {{2, 1, 1}, {3, 2, 1}, {3, 4, 2}},
        {{2, 1, 1}, {1, 3, 1}, {3, 4, 2}, {5, 4, 2}},
        {{1, 2, 1}, {2, 3, 1}, {3, 4, 1}},
        {{1, 2, 1}, {2, 3, 1}, {3, 5, 2}},
        {{1, 2, 2}}
    };

    std::vector<int> n = {4, 5, 4, 5, 2};
    std::vector<int> k = {3, 1, 1, 1, 2};

    for (int i = 0; i < times.size(); ++i) {
        std::cout << i + 1 << ".\t times = [";
        for (auto it = times[i].begin(); it != times[i].end(); ++it) {
            std::cout << "[" << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2] << "]";
            if (it != times[i].end() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
        std::cout << "\t number of nodes 'n' = " << n[i] << "\n";
        std::cout << "\t starting node 'k' = " << k[i] << "\n\n";
        std::cout << "\t Minimum amount of time required = " << NetworkTimeDelay(times[i], n[i], k[i]) << "\n";
        std::cout << std::string(100, '-') << "\n";
    }

    return 0;
}