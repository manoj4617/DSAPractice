#include "BinaryTree.h"
#include <cstddef>
#include <ctype.h>
#include <exception>

using namespace std;

/**
 * This function takes a binary tree and returns a vector of two integers.
 * The first element of the vector is the maximum amount of money that can
 * be stolen from the house and all of its descendants, assuming that the
 * root of the tree is included in the heist.
 * The second element of the vector is the maximum amount of money that can
 * be stolen from the house and all of its descendants, assuming that the
 * root of the tree is not included in the heist.
 */
vector<int> Heist(TreeNode<int>* root){
    if(root == nullptr){
        /*
         * If the tree is empty, then the maximum amount of money that can be
         * stolen is 0, with or without the root of the tree.
         */
        return {0,0};
    }
    
    /*
     * Recursively get the maximum amount of money that can be stolen from
     * the left subtree and the right subtree.
     */
    vector<int> leftsubtree = Heist(root->left);
    vector<int> rightsubtree = Heist(root->right);

    /*
     * Calculate the maximum amount of money that can be stolen if the root
     * of the tree is included in the heist.
     * This is done by adding the value of the root to the maximum amount of
     * money that can be stolen from the left subtree and the right subtree,
     * both of which are calculated without including the root of the
     * subtree.
     */
    int includeRoot = root->data + leftsubtree[1] + rightsubtree[1];

    /*
     * Calculate the maximum amount of money that can be stolen if the root
     * of the tree is not included in the heist.
     * This is done by taking the maximum of the maximum amount of money that
     * can be stolen from the left subtree and the right subtree, both of
     * which are calculated without including the root of the tree.
     */
    int excludeRoot = max(leftsubtree[0], leftsubtree[1]) + max(rightsubtree[0], rightsubtree[1]);

    /*
     * Return a vector with the two calculated values.
     */
    return {includeRoot, excludeRoot};
}


int Rob(TreeNode<int>* root){
    vector<int> res = Heist(root);
    return max(res[0],res[1]);
}

void DisplayTree(TreeNode<int>* root){
    if(root == nullptr){
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int level = q.size();
        for(int i=0;i<level;++i){
            TreeNode<int>* current = q.front();
            q.pop();
            if(current){
                cout << current->data << " ";
                q.push(current->left);
                q.push(current->right);
            }
            else{
                cout << "null ";
            }
        }
        cout << endl;
    }
}

int main() {
    std::vector<std::vector<TreeNode<int>*>> listOfTrees = { {new TreeNode<int>(10), new TreeNode<int>(9), new TreeNode<int>(20), new TreeNode<int>(15), new TreeNode<int>(7)},
                    { new TreeNode<int>(7), new TreeNode<int>(9), new TreeNode<int>(10), new TreeNode<int>(15), new TreeNode<int>(20)},
                    { new TreeNode<int>(8), new TreeNode<int>(2), new TreeNode<int>(17), new TreeNode<int>(1), new TreeNode<int>(4), new TreeNode<int>(19), new TreeNode<int>(5)},
                    { new TreeNode<int>(7), new TreeNode<int>(3), new TreeNode<int>(4), new TreeNode<int>(1), new TreeNode<int>(3)},
                    { new TreeNode<int>(9), new TreeNode<int>(5), new TreeNode<int>(7), new TreeNode<int>(1), new TreeNode<int>(3)},
                    { new TreeNode<int>(9), new TreeNode<int>(7), nullptr, nullptr, new TreeNode<int>(1), new TreeNode<int>(8), new TreeNode<int>(10), nullptr, new TreeNode<int>(12)}
    };

    std::vector<BinaryTree<int>> inputTrees;
    for (const std::vector<TreeNode<int>*> listOfNodes : listOfTrees) {
        BinaryTree<int> tree(listOfNodes);
        inputTrees.push_back(tree);
    }

    int x = 1;
    for (const BinaryTree<int> tree : inputTrees) {
        std::cout << x << ".\tInput Tree: " << std::endl;
        DisplayTree(tree.root);
        x += 1;
        std::cout << "\tMaximum amount we can rob without getting caught: " << Rob(tree.root) << std::endl;
        std::cout << std::string(100,'-') << "\n";
    }

    return 0;
}