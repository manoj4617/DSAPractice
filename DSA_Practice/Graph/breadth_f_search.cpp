#include "AdjacencyList.h"


void Graph::BFS_using_queue(int startingVertex, int endingVertex){
    std::vector<int> parents(-1);
    std::queue<int> queue;
    std::vector<int> dis;
    dis[startingVertex] = 0;
    queue.push(startingVertex);

    while(!queue.empty()){
        int front = queue.front();
        queue.pop();

        std::cout << front << "\t";
        for(const int &v : adjList[front]){
            if(parents[v] == -1 && !visited[v]){
                parents[v] = front;
                visited[v] = true;
                dis[v] = dis[front] + 1;
                queue.push(v);
            }
        }
    }

    std::vector<int> path;
    for(int i= endingVertex; i != -1; i = parents[i]){
        path.push_back(i);
    }
    std::reverse(path.begin(), path.end());
    for(int i : path){
        std::cout << i << " ";
    }
}

int main(){
    int n, x, y;


    std::cin >> n;

    Graph graph(n);
  
    for(int i=0; i<n; ++i){
        std::cin >> x >> y;
        graph.addEdge(x, y);
    }
    int end;
    std::cin >> end;
    std::cout << "Graph : " << "\n";
    graph.BFS_using_queue(0, end);
    std::cout << "\n";

}
