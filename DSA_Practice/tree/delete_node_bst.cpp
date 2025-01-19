#include <iostream>
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
 * Deletes a node with a given key from a binary search tree.
 *
 * @param root The root of the binary search tree.
 * @param key The key of the node to be deleted.
 * @return The root of the modified binary search tree.
 */
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;

    /*
     * If the node to be deleted is in the left subtree of the root, then
     * recursively call deleteNode on the left subtree.
     */
    if(root->val > key){
        root->left = deleteNode(root->left, key);
    }
    /*
     * If the node to be deleted is in the right subtree of the root, then
     * recursively call deleteNode on the right subtree.
     */
    else if(root->val < key){
        root->right = deleteNode(root->right, key);
    }
    /*
     * If the node to be deleted is the root itself, then there are three cases:
     * 1. If the root has no children, then delete the root and return nullptr.
     * 2. If the root only has a left child, then delete the root and return the left child.
     * 3. If the root only has a right child, then delete the root and return the right child.
     * 4. If the root has both left and right children, then find the inorder successor of the root
     *    (i.e. the smallest node in the right subtree), copy its value to the root, and then delete the
     *    inorder successor from the right subtree.
     */
    else{
        if(!root->right && !root->left){
            delete root;
            return nullptr;
        }
        if(!root->right){
            TreeNode* temp = root->left;
            delete root;
            return temp;    
        }
        if(!root->left){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        TreeNode* cur = root->right;
        while(cur->left){
            cur = cur->left;
        }
        root->val = cur->val;
        root->right = deleteNode(root->right, cur->val);
    }
    return root;
}

void printTree(TreeNode* root){
    if(!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    printTree(root);
    deleteNode(root, 3);
    cout << endl;
    printTree(root);

    return 0;
}