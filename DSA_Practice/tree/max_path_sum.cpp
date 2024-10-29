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
 * This function uses a recursive approach to find the maximum path sum. The
 * base case of the recursion is when the node is null, in which case the
 * function returns 0.
 *
 * Otherwise, the function recursively calls itself on the left and right
 * children of the node. The result of the recursive call is the maximum path
 * sum that can be obtained by traversing the subtree rooted at the left or
 * right child. The maximum path sum is then updated by taking the maximum of
 * the current maximum path sum and the sum of the value of the node itself and
 * the result of the recursive call on the left and right children.
 *
 * The function also handles the case if a node has a negative value or any
 * subtree returning negative path sum by returning 0 in such cases. This is
 * done by taking the maximum of the result of the recursive call and 0.
 *
 * Finally, the function returns the value of the node plus the maximum of the
 * values returned by the recursive calls on the left and right children. This
 * is the maximum path sum that can be obtained by traversing the tree from the
 * given node.
 */
int dfs(Node* root, int& res){
    // Base case: If the node is null, return 0
    if(!root) return 0;

    // Recursively call the function on the left and right children of the node
    int leftSum = max(dfs(root->left_child, res), 0);
    int rightSum = max(dfs(root->right_child, res), 0);

    // Update the maximum path sum
    res = max(res , root->data + leftSum + rightSum);

    // Return the value of the node plus the maximum of the values returned by
    // the recursive calls on the left and right children
    return root->data + max(leftSum , rightSum);
}
int MaxSumPathHelper(Node* root){
    int res = root->data;
    dfs(root, res);
    return res;
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