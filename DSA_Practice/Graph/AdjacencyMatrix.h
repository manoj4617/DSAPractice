#include <iostream>
#include <vector>
#include <tuple>

class AdjancencyMatrix {
    private:
        std::vector<int> adj;
        int n;
    
    public:
        AdjancencyMatrix(int _n)
            :n {_n},
             adj {std::vector<int>(_n * _n, 0)}
        {}

    void add_edge(int source, int target, int weight){
        if(!this->adj[this->n * source + target]){
            this->adj[this->n * source + target] = (weight != 0 ? weight : 0);
        }
    }

    void remove_edge(int source, int target){
        this->adj[this->n * source + target] = 0;   
    }

    int get_edge(int source, int target){
        return this->adj[this->n * source + target];
    }
};
