#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

bool ValidTree(int n, std::vector<std::vector<int>>& edges) {
    // A valid tree should have exactly n-1 edges
    if (edges.size() != n - 1) {
        return false;
    }

    // Create an adjacency list to represent the graph
    std::vector<std::vector<int>> adjacency(n);
    for (const auto& edge : edges) {
        // Extract the nodes of the edge
        int x = edge[0];
        int y = edge[1];
        // Add each node to the other's adjacency list
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }

    // A set to keep track of visited nodes
    std::unordered_set<int> visited;
    // A stack to perform a depth-first search (DFS)
    std::stack<int> stack;
    // Start the DFS from node 0
    visited.insert(0);
    stack.push(0);

    // Perform DFS
    while (!stack.empty()) {
        // Get the current node
        int node = stack.top();
        stack.pop();

        // Traverse all the neighbors of the current node
        for (int neighbor : adjacency[node]) {
            // If the neighbor hasn't been visited
            if (visited.find(neighbor) == visited.end()) {
                // Mark it as visited
                visited.insert(neighbor);
                // Add it to the stack for further exploration
                stack.push(neighbor);
            }
        }
    }

    // Check if all nodes were visited (graph is connected)
    return visited.size() == n;
}

// Driver code
int main() {
    std::vector<int> n = {3, 4, 5, 5, 6};
    std::vector<std::vector<std::vector<int>>> edges = {
        {{0, 1}, {0, 2}, {1, 2}},
        {{0, 1}, {0, 2}, {0, 3}},
        {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {3, 4}},
        {{0, 1}, {0, 2}, {0, 3}, {3, 4}},
        {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {0, 5}}
    };

    for (size_t i = 0; i < n.size(); ++i) {
        std::cout << i + 1 << ". n = " << n[i] << std::endl;
        std::cout << "   Edges = ";
        for (const auto& edge : edges[i]) {
            std::cout << "[" << edge[0] << ", " << edge[1] << "] ";
        }
        std::cout << std::endl;
        std::cout << "   Is the given graph a valid tree: " << std::boolalpha << ValidTree(n[i], edges[i]) << std::endl;
        std::cout << "-" << std::string(100, '-') << std::endl;
    }

    return 0;
}