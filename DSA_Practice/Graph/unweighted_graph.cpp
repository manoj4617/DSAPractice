#include "AdjacencyMatrix.h"

int main(){
    int n = 5;

    AdjancencyMatrix adjMatrix(n);

    std::vector<std::tuple<int,int,int>> edges {
        std::make_tuple(0,1,0),
        std::make_tuple(1,2,0),
        std::make_tuple(1,3,0),
        std::make_tuple(2,0,0),
        std::make_tuple(1,0,0),
        std::make_tuple(2,3,0)
    };

    for(auto [u, v, w]: edges){
        adjMatrix.add_edge(u,v,w); 
    }

    std::cout << "Edge from 0 to 1: " << adjMatrix.get_edge(0,1) << "\n";
    std::cout << "No Edge from 0 to 3: " << adjMatrix.get_edge(0,3) << "\n";

    return 0;
}