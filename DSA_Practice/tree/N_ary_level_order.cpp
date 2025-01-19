#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * This function performs a level order traversal of an N-ary tree and returns a
 * vector of vectors of integers. The outer vector represents the levels of the
 * tree, and the inner vectors represent the nodes at each level.
 *
 * @param root The root of the N-ary tree.
 *
 * @return A vector of vectors of integers, where the outer vector represents the
 * levels of the tree, and the inner vectors represent the nodes at each level.
 */
vector<vector<int>> levelOrder(Node* root) {
    if(!root) return {};

    /**
     * Initialize a queue to store the nodes to be processed. The queue is
     * initialized with the root node.
     */
    queue<Node*> q;
    q.push(root);

    /**
     * Initialize a vector to store the result of the level order traversal. The
     * outer vector represents the levels of the tree, and the inner vectors
     * represent the nodes at each level.
     */
    vector<vector<int>> res;

    /**
     * This loop will continue until all nodes in the tree have been visited.
     * It uses a queue to keep track of the nodes that need to be visited.
     */
    while(!q.empty()){
        /**
         * Get the number of nodes at the current level.
         */
        int len = q.size();

        /**
         * Initialize a temporary vector to store the node values at the
         * current level.
         */
        vector<int> temp;

        /**
         * This loop will process all nodes at the current level.
         */
        for(int i=0;i<len;++i){
            /**
             * Pop the current node off the queue and add its value to the
             * temporary vector.
             */
            Node* node = q.front();
            temp.push_back(node->val);
            q.pop();

            /**
             * Add all children of the current node to the queue.
             */
            for(auto& n : node->children){
                q.push(n);
            }
        }

        /**
         * Add the temporary vector to the result vector.
         */
        res.push_back(temp);
    }

    /**
     * Return the result vector.
     */
    return res;
}

int main(){
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    root->children[0]->children.push_back(new Node(7));
    root->children[1]->children.push_back(new Node(8));
    root->children[1]->children.push_back(new Node(9));
    root->children[2]->children.push_back(new Node(10));

    vector<vector<int>> res = levelOrder(root);
    for(auto& v : res){
        for(auto& n : v){
            cout << n << " ";
        }
        cout << endl;
    }

    return 0; 
}