#include "tree.h"

using namespace std;

/**
 * This function takes a pointer to the root of a binary tree and returns a
 * pointer to a new binary tree which is the mirror image of the original
 * tree.
 *
 * The algorithm works by recursively traversing the tree in a pre-order
 * fashion, and swapping the left and right subtrees of each node.
 *
 * If the root of the tree is a nullptr, then the function simply returns a
 * nullptr.
 *
 * Otherwise, the function first recursively calls itself on the left subtree
 * of the root, then on the right subtree of the root. This is done to ensure
 * that the left and right subtrees are properly swapped for all nodes in the
 * tree, not just the root.
 *
 * Then, the function swaps the left and right child pointers of the root node.
 *
 * Finally, the function returns the root of the new tree, which is the
 * mirror image of the original tree.
 */
Node* InvertTree(Node* root){
    if(!root){
        /*
         * If the root of the tree is a nullptr, then the function simply
         * returns a nullptr.
         */
        return nullptr;
    }

    /*
     * Recursively call this function on the left subtree of the root.
     */
    if(root->left_child){
        InvertTree(root->left_child);
    }

    /*
     * Recursively call this function on the right subtree of the root.
     */
    if(root->right_child){
        InvertTree(root->right_child);
    }

    /*
     * Swap the left and right child pointers of the root node.
     */
    Node* temp = root->left_child;
    root->left_child = root->right_child;
    root->right_child = temp;

    /*
     * Return the root of the new tree, which is the mirror image of the
     * original tree.
     */
    return root;
}

int main(){
    Tree* tree = new Tree();
    tree->create_tree();
    tree->post_order(tree->root);
    tree->root = InvertTree(tree->root);
    cout << "\n";
    tree->post_order(tree->root);
}