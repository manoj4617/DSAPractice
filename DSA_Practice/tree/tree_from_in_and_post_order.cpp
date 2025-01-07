#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * This is a helper function that builds a binary tree from a given postorder and
 * inorder traversal of the tree.
 *
 * The function takes the following parameters:
 *  - l: The leftmost index of the current subtree in the inorder traversal.
 *  - r: The rightmost index of the current subtree in the inorder traversal.
 *  - mp: A hashmap that maps each node's value to its index in the inorder traversal.
 *  - postorder: A vector of node values in the postorder traversal of the tree.
 *  - last: A reference to an integer that keeps track of the current index in the
 *    postorder vector. This index is decremented as the function recuses.
 *
 * The function returns a pointer to the root of the current subtree.
 */
TreeNode* helper(int l, int r, unordered_map<int,int>& mp, vector<int>& postorder, int& last){
    if(l > r){
        // If the current subtree is empty, return nullptr.
        return nullptr;
    }

    // Create a new TreeNode with the value at the current index in the postorder vector.
    TreeNode* root = new TreeNode(postorder[last--]);

    // Find the index of the current node in the inorder traversal.
    int idx = mp[root->val];

    // Recursively build the right subtree, with the current node as the root.
    // The range of the right subtree is from idx + 1 to r.
    root->right = helper(idx + 1, r, mp, postorder, last);

    // Recursively build the left subtree, with the current node as the root.
    // The range of the left subtree is from l to idx - 1.
    root->left = helper(l, idx - 1, mp, postorder, last);
    
    // Return the root of the current subtree.
    return root;
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();++i){
        mp[inorder[i]] = i;
    }
    int last = postorder.size()-1;
    return helper(0, inorder.size() - 1, mp, postorder, last);
}

void printTree(TreeNode* root){
    if(root == nullptr){
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main(){
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(postorder, inorder);
    printTree(root);
    return 0;
}