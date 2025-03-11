#include <iostream>
#include <vector>


using namespace std;


void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int stone){
    visited[stone] = true;

    for(int n : adjList[stone]){
        if(!visited[n]){
            dfs(adjList, visited, n);
        }
    }
}

/*
Theory behind the solution:
1. Two stones can be on the same row or column to remove one of them
2. This creates a natural graph where stones are connected if they share a row or column
3. In each connected component, we can remove all stones except one
   - This is because we can always follow the connections to remove stones until one remains
4. Therefore, the maximum stones we can remove is:
   total stones - number of connected components
*/

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    // Create adjacency list representation of the graph
    // where stones are nodes and edges connect stones on same row/column
    vector<vector<int>> adjList(n);

    // Build the graph: connect stones that share same row (x) or column (y)
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(stones[i][0] == stones[j][0] ||  // same row (x-coordinate)
                stones[i][1] == stones[j][1]){   // same column (y-coordinate)
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
        }
    }

    // Use DFS to count connected components
    vector<bool> visited(n, false);
    int numConnectedComponents = 0;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfs(adjList, visited, i);
            numConnectedComponents++;  // Each DFS call finds one connected component
        }
    }
    
    // For each connected component, we can remove all stones except one
    // So maximum removable stones = total stones - number of components
    return n - numConnectedComponents;
}

int main(){
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

    cout << removeStones(stones) << endl;
    return 0;
}