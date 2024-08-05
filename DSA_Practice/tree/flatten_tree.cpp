#include "tree.h"


/*
This function takes a binary tree as input and flattens it into a single level structure.
It does this by rearranging the pointers of the nodes in the tree to create a linked list.

The function takes a pointer to the root of the binary tree as input.
It returns a pointer to the root of the flattened tree.
*/

Node* Flatten_tree(Node* root){
    // If the root is null, there is nothing to flatten, so return nullptr.
    if(!root) return nullptr;

    // Initialize a pointer to the current node as the root.
    Node* cur = root;

    // Loop through each node in the tree.
    while(cur){
        // If the current node has a left child, we need to flatten the left subtree.
        if(cur->left_child){
            // Find the rightmost node in the left subtree.
            Node* last = cur->left_child;
            while(last->right_child){
                last = last->right_child;
            }

            // Connect the right child of the current node to the rightmost node in the left subtree.
            last->right_child = cur->right_child;

            // Connect the right child of the current node to the left child of the current node.
            cur->right_child = cur->left_child;

            // Set the left child of the current node to null.
            cur->left_child = nullptr;
        }

        // Move the current node to its right child.
        cur = cur->right_child;
    }

    // Return the root of the flattened tree.
    return root;
}

int main(){
    Tree *t = new Tree();
    t->create_tree();
    t->root = Flatten_tree(t->root);
    t->level_order(t->root);

    return 0;
}

