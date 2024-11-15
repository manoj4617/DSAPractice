#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void dfs(vector<vector<int>>& adjList, int src, vector<bool>& visit){
    visit[src] = true;

    for(auto& c : adjList[src]){
        if(!visit[abs(c)]){
            if(c > 0){
                count++;        // if it is positive means there is a path from src -> dest
                                // but the path should be from dest -> src
            }
            dfs(adjList, abs(c), visit);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections){
    if(n == 0){
        return 0;
    }

    vector<vector<int>> adjList(n);
    vector<bool> visited(n, false);

    for(auto& u : connections){
        adjList[u[0]].push_back(u[1]);      // having a positive neighbor means the path has to be reversed
        adjList[u[1]].push_back(-u[0]);     // having a negative neighbor means there is a path to to 0
    }

    dfs(adjList, 0, visited);
    return count;
}

int main(){
    vector<vector<int>> A = {{0,1},{1,2},{2,3},{3,4},{4,0},{4,5},{5,0}};

    int n = A.size();

    for(int i = 0; i < n; ++i){
        cout << i + 1 << ".\t A = [";
        for(int j = 0; j < A[i].size(); ++j){
            cout << A[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << endl;
    cout << minReorder(n, A) << endl;
    return 0;
}