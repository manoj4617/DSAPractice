#include <iostream>
#include <vector>

using namespace std;

/**
 * This is a depth-first search function that traverses the tree and returns the
 * minimum time required to collect all the apples in the tree.
 *
 * @param cur The current node being processed.
 * @param parent The parent of the current node.
 * @param adj The adjacency list of the tree.
 * @param hasApple A vector of bools that indicates whether each node has an
 * apple.
 *
 * @return The minimum time required to collect all the apples in the tree.
 */
int dfs(int cur, int parent, vector<vector<int>>& adj, vector<bool>& hasApple){
    int time = 0;

    /**
     * Iterate over all the children of the current node.
     */
    for(auto& child : adj[cur]){
        if(cur == parent){
            /**
             * Skip the parent node, because we don't want to revisit the parent
             * node.
             */
            continue;
        }

        /**
         * Recursively call this function on each child node.
         */
        int childTime = dfs(child, cur, adj, hasApple);

        /**
         * If the child node has an apple, or if the child node has a subtree
         * that contains an apple, then we need to add the time required to
         * collect that apple to the total time.
         */
        if(childTime  || hasApple[child]){
            time += 2 + childTime;
        }
    }
    return time;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
    vector<vector<int>> adj (n);
    for(auto& edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return dfs(0, -1, adj, hasApple);
}


int main(){
    int n = 7;
    vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple = {false,false,true,false,true,true,false};
    cout << "Minimum time to collect all apples: " << minTime(n, edges, hasApple);
    return 0;
}