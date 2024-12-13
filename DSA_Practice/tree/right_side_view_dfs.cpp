#include "tree.h"

using namespace std;

/**
 * This is a recursive depth-first search function that traverses a binary tree
 * and records the rightmost node at each level in the result vector.
 *
 * @param node The current node being processed.
 * @param res The result vector to store the rightmost nodes at each level.
 * @param level The current level being processed.
 */
void dfs(Node* node, vector<int>& res, int level){
    if(!node) return;

    /**
     * If the result vector does not have a node at the current level, add the
     * current node to the result vector. This ensures that the rightmost node
     * at each level is recorded.
     */
    if(res.size() == level){
        res.push_back(node->data);
    }

    /**
     * Recursively call this function on the right subtree of the current node
     * (if it exists). This ensures that the rightmost node at each level is
     * recorded.
     */
    dfs(node->right_child, res, level + 1);

    /**
     * Recursively call this function on the left subtree of the current node
     * (if it exists). This ensures that the leftmost node at each level is
     * recorded, but only if the right subtree does not exist.
     */
    dfs(node->left_child, res, level + 1);
}

vector<int> rightSideViewDFS(Node* root){
    if(!root) return {};
    vector<int> res;
    int level = 0;
    dfs(root, res, level);
    return res;
}

int main(){
    Tree* tree;
    tree->create_tree();
    vector<int> res = rightSideViewDFS(tree->root);
    for(int& r : res){
        cout << r << " ";
    }
}