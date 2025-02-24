/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 #include <iostream>
 #include <vector>

 using namespace std;
class Solution {
public:

    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result){
        if(!root) return;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr &&
            targetSum == root->val){
            result.push_back(path);
        }else 
        {
            if(root->left){
                dfs(root->left, targetSum - root->val, path, result);
            }
            if(root->right){
                dfs(root->right, targetSum - root->val, path, result);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> result;
        dfs(root, targetSum, path, result);
        return result;
    }
};
// @lc code=end


int main(){
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    vector<vector<int>> result = s.pathSum(root, 22);
    for(auto& path : result){
        for(auto& val : path){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
