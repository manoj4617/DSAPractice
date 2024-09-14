#include "tree.h"
#include <algorithm>

using namespace std;

/**
 * This function takes in a vector of sorted integers and returns the root of a balanced binary
 * search tree created from the vector. The tree is created by recursively dividing the vector
 * into two halves and creating a node with the middle element as the root, and then creating the
 * left and right subtrees in the same way.
 *
 * @param nums The vector of sorted integers to create the tree from.
 * @param low The index of the first element in the current range of the vector.
 * @param high The index of the last element in the current range of the vector.
 * @return The root of the created tree.
 */
Node* SortedArrayToTree(vector<int>& nums, int low , int high){
    // If the range is empty, return null
    if(low > high){
        return nullptr;
    }

    // Calculate the index of the middle element in the current range
    int mid = low + (high - low) / 2;

    // Create a new node with the middle element
    Node* root = new Node(nums[mid]);

    // Recursively create the left subtree with the elements before the middle element
    root->left_child = SortedArrayToTree(nums, low, mid - 1);

    // Recursively create the right subtree with the elements after the middle element
    // Note: There is a bug in the original code where the left child is assigned twice
    root->right_child = SortedArrayToTree(nums, mid + 1, high);

    // Return the root of the created tree
    return root;
}

Node* ArraytoTree(vector<int>& nums){
    int n = nums.size();
    return SortedArrayToTree(nums,0,n-1);
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    Tree* tree = new Tree;
    tree->root = ArraytoTree(nums);
    tree->post_order(tree->root);
}