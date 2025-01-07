#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "tree.h"

using namespace std;


/**
 * This function takes a pointer to a Node as input and returns a vector of vectors of integers.
 * The outer vector represents the vertical order of the tree, and the inner vectors represent the
 * nodes in each vertical order.
 *
 * The function uses a breadth-first search approach to traverse the tree. It uses a queue to keep
 * track of the nodes to be processed, and a map to keep track of the vertical order of each node.
 *
 * The function starts by pushing the root node onto the queue with a column value of 0. Then, it
 * enters a loop where it pops a node off the queue, checks if it's not null, and if so, pushes its
 * left and right children onto the queue with column values of column - 1 and column + 1
 * respectively. It also keeps track of the minimum and maximum column values encountered so far.
 *
 * After the loop is finished, the function iterates over the range of column values from the minimum
 * to the maximum, and for each column, it adds the corresponding vector of node values to the result
 * vector.
 *
 * Finally, the function returns the result vector.
 */
vector<vector<int>> verticalOrder(Node* root) {
    if(!root) return {};

    /**
     * The result vector will store the vertical order of the tree. Each inner vector represents
     * the nodes in a particular vertical order.
     */
    vector<vector<int>> res;

    /**
     * The map will store the nodes in each vertical order. The key is the column value, and the
     * value is a vector of node values.
     */
    unordered_map<int, vector<int>> nodeList;

    /**
     * The queue will store the nodes to be processed, along with their column values.
     */
    queue<pair<Node*, int>> q;

    /**
     * Initialize the column value to 0.
     */
    int column = 0;

    /**
     * Push the root node onto the queue with a column value of 0.
     */
    q.push({root, column});

    /**
     * Initialize the minimum and maximum column values to 0.
     */
    int minCol = 0;
    int maxCol = 0;

    /**
     * Enter a loop where we pop a node off the queue, check if it's not null, and if so, push its
     * left and right children onto the queue with column values of column - 1 and column + 1
     * respectively.
     */
    while(!q.empty()){
        pair<Node*, int> p = q.front();
        root = p.first;
        column = p.second;
        q.pop();

        if(root != nullptr){
            /**
             * Keep track of the minimum and maximum column values encountered so far.
             */
            maxCol = max(maxCol, column);
            minCol = min(minCol, column);

            /**
             * Add the node's value to the corresponding vector in the map.
             */
            nodeList[column].push_back(root->data);

            /**
             * Push the left and right children onto the queue with column values of column - 1
             * and column + 1 respectively.
             */
            if(root->left_child){
                q.push({root->left_child, column - 1});
            }
            if(root->right_child){
                q.push({root->right_child, column + 1});
            }
        }
    }

    /**
     * Iterate over the range of column values from the minimum to the maximum, and for each column,
     * add the corresponding vector of node values to the result vector.
     */
    for(int i = minCol; i < maxCol + 1; i++){
        res.push_back(nodeList[i]);
    }

    /**
     * Return the result vector.
     */
    return res;
}

int main(){
    Tree* tree = new Tree();
    tree->create_tree();
    vector<vector<int>> res = verticalOrder(tree->root);
    for(auto i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}