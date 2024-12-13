#include "tree.h"
#include <queue>

using namespace std;

/**
 * This function takes a pointer to a Node as input and returns a vector of integers
 * where each element is the value of the rightmost node at each level in the binary
 * tree.
 *
 * The function uses a queue to perform a breadth-first search of the tree. It
 * starts by pushing the root node onto the queue. Then, it enters a loop where it
 * pops a node off the queue, checks if it's not null, and if so, pushes its left
 * and right children onto the queue. It keeps track of the rightmost node at each
 * level by storing the value of the last node it encountered in the loop. If the
 * rightmost node is not null, it adds its value to the result vector.
 *
 * After the loop is finished, the function returns the result vector.
 */
vector<int> rightSideViewBFS(Node* root){
    if(!root){
        return {};
    }

    queue<Node*> q;
    q.push(root);
    vector<int> res;

    while(!q.empty()){
        int len = q.size();
        Node* rightSide = nullptr;
        for(int i=0;i<len;++i){
            Node* node = q.front();
            q.pop();

            if(node){
                rightSide = node;
                q.push(node->left_child);
                q.push(node->right_child);
            }
        }
        if(rightSide){
            res.push_back(rightSide->data);
        }
    }

    return res;
}

int main(){
    Tree* tree;
    tree->create_tree();
    vector<int> res = rightSideViewBFS(tree->root);
    for(int& r : res){
        cout << r << " ";
    }
}