#include "AdjacencyList.h"



void Graph::DFS_using_stack(int startingVertex){
  std::vector<bool> visited(vertices, false);
  std::stack<int> st;

  st.push(startingVertex);

  while(!st.empty()){                               //Iterate till the stack is empty
    int currentVertex = st.top();                   //get the top element of the stack
    st.pop();                                       //pop the top element
    if(!visited[currentVertex]){                    //check if the current element is visited or not  
      std::cout << currentVertex << " ";          
      visited[currentVertex] = true;
      for(const auto &v : adjList[currentVertex]){  //if not visited then add all its neighbours to the stack
        if(!visited[v]){
          st.push(v);
        }
      }
    }
  }   
}

void Graph::DFS_using_recurssion(std::vector<bool>  visited, int vertex){
  visited[vertex] = true;
  std::cout << vertex << " ";
  for(const auto &node : adjList[vertex]){
    if(!visited[node]){
      DFS_using_recurssion(visited, node);
    }
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
  
  std::cout << "Graph : " << "\n";

  // graph.printGraph();
  graph.DFS_using_stack(0);
  std::cout << "\n";
  //graph.DFS_using_recurssion(graph.visited, 0);

  return 0;
}


