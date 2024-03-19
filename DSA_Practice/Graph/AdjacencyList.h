#include <iostream>
#include <vector>
#include <stack>
#include <queue>

class Graph{
        int vertices;

    public:
        std::vector<std::vector<int>> adjList;
        std::vector<bool> visited;
        Graph(int num_vertices){
            vertices = num_vertices;
            adjList.resize(num_vertices);
            visited.resize(num_vertices, false);
        }

        void addEdge(int source, int destination){
            adjList[source].push_back(destination);
            adjList[destination].push_back(source); //for undirected graph
        }  

        void printGraph(){
            for(int i=0; i<vertices; ++i){
                std::cout << "Vertex " << i << "is connected to "; 
                for(auto node : adjList[i]){
                    std::cout << node << " ";
                }
                std::cout << "\n";
            }
        }

        void DFS_using_stack(int startingVertex);
        void DFS_using_recurssion(std::vector<bool> visited, int neighbor);

        void BFS_using_queue(int startingVertex);
};