#include "tree.h"
#include <algorithm>

using namespace std;

int MaxSum = INT_MIN;

/**
 * This function takes a node in a tree as an argument and returns the maximum
 * path sum that can be obtained by traversing the tree from that node. The
 * maximum path sum is defined as the maximum sum of the values of all nodes
 * in a path from the given node to any other node in the tree.
 *
 * This function uses a recursive approach to find the maximum path sum. It
 * first checks if the node is null, and if so, returns 0. Then, it recursively
 * calls itself on the left and right children of the node and checks if the
 * sum of the values of the left and right children plus the value of the node
 * itself is greater than the current maximum path sum. If so, it updates the
 * maximum path sum. Finally, it returns the value of the node plus the maximum
 * of the values returned by the recursive calls on the left and right
 * children.
 *
 * Note: This function handles the case if a node has a negative value or any
 * subtree returning negative path sum by returning 0 in such cases.
 */
int MaxSumPathHelper(Node* root){
    if(!root){
        return 0;
    }

    // Recursively call this function on the left and right children
    int leftSum = max(MaxSumPathHelper(root->left_child),0);
    int rightSum = max(MaxSumPathHelper(root->right_child),0);

    // Calculate the maximum path sum that can be obtained by traversing the
    // tree from the given node
    int valMax = root->data + leftSum + rightSum;
    // Update the maximum path sum if the current maximum path sum is greater
    // than the maximum path sum obtained so far
    MaxSum = max(MaxSum, valMax);

    // If the value of the node plus the maximum of the values returned by the
    // recursive calls on the left and right children is negative, return 0.
    // Otherwise, return the value of the node plus the maximum of the values
    // returned by the recursive calls on the left and right children.
    return root->data + max(leftSum, rightSum);
}


/**
 * This function takes a node in a tree as an argument and returns the maximum
 * path sum that can be obtained by traversing the tree from the given node.
 *
 * The function first calls the helper function MaxSumPathHelper on the given
 * node. This function recursively computes the maximum path sum that can be
 * obtained by traversing the tree from the given node. The function then
 * stores the maximum path sum in the variable temp and resets the maximum
 * path sum to negative infinity.
 *
 * Finally, the function returns the maximum path sum that was stored in the
 * variable temp.
 */
int MaxSumPath(Node* root){
    // Call the helper function to compute the maximum path sum
    MaxSumPathHelper(root);

    // Store the maximum path sum in the variable temp
    int temp = MaxSum;

    // Reset the maximum path sum to negative infinity
    MaxSum = INT_MIN;

    // Return the maximum path sum that was stored in the variable temp
    return temp;
}

int main(){
    Tree* tree = new Tree();
    tree->create_tree();
    cout << MaxSumPath(tree->root);
}