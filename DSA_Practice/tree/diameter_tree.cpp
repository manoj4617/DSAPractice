#include "tree.h"

// The time complexity of this algorithm is O(n) where n is the number of nodes in the tree.
// The space complexity of this algorithm is O(h) where h is the height of the tree.
// This algorithm calculates the height of a binary tree and also calculates and returns the diameter of the tree.
// The diameter of a tree is the maximum distance between any two nodes in the tree.
// The diameter is used to evaluate the efficiency of the tree.
// The function takes two parameters:
// - node: a pointer to the root node of the binary tree.
// - dia: a reference to an integer that will hold the diameter of the tree.
// The function returns an integer representing the height of the subtree rooted at the given node.
int cal_height(Node* node, int &dia){
    // If the node is a NULL pointer, return 0 indicating that the tree has no more nodes.
    if(!node) return 0;

    // Recursively calculate the heights of the left and right subtrees of the given node.
    int lh = cal_height(node->left_child, dia);  // lh stands for left height
    int rh = cal_height(node->right_child, dia); // rh stands for right height

    // Update the diameter of the tree by taking the maximum of the current diameter and the sum of the heights of the left and right subtrees.
    // The diameter is used to evaluate the efficiency of the tree.
    dia = std::max(dia, lh + rh);

    // Return the maximum of the heights of the left and right subtrees plus 1.
    // This is the height of the subtree rooted at the given node.
    return std::max(lh,rh) + 1;
}

int DiameterofTree(Node* root){
    int dia = 0;
    cal_height(root,dia);
    return dia;
}