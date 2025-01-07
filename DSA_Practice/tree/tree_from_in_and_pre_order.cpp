#include <iostream>
#include <unordered_map>
#include <vector>

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
 * This is a helper function for the buildTree function. It takes four parameters:
 *   l: The leftmost index of the current subtree in the inorder traversal.
 *   r: The rightmost index of the current subtree in the inorder traversal.
 *   mp: A hashmap that maps each node's value to its index in the inorder traversal.
 *   pre: The preorder traversal of the tree.
 *   first: A reference to an integer that keeps track of the current index in the
 *     preorder vector. This index is incremented as the function recurses.
 *
 * The function returns a pointer to the root of the current subtree.
 */
TreeNode* helper(int l, int r, unordered_map<int, int>& mp, vector<int>& pre, int& first){
    if(l > r){
        // If the current subtree is empty, return nullptr.
        return nullptr;
    }

    // Create a new TreeNode with the value at the current index in the preorder vector.
    TreeNode* root = new TreeNode(pre[first++]);
    
    // Find the index of the current node in the inorder traversal.
    int idx = mp[root->val];

    // Recursively build the left subtree, with the current node as the root.
    // The range of the left subtree is from l to idx - 1.
    root->left = helper(l, idx - 1, mp, pre, first);

    // Recursively build the right subtree, with the current node as the root.
    // The range of the right subtree is from idx + 1 to r.
    root->right = helper(idx + 1, r, mp, pre, first);

    // Return the root of the current subtree.
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    unordered_map<int, int> mp;
    for(int i=0;i<inorder.size(); ++i){
        mp[inorder[i]] = i;
    }

    int first = 0;
    return helper(0, inorder.size() - 1, mp, preorder, first);
}

void printTree(TreeNode* root){
    if(!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    printTree(root);
    return 0;
}