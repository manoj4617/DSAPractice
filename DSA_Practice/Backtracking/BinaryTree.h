#pragma once
#include <vector>
#include <queue>
#include <iostream>

template<class T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
};

template<class T>
class BinaryTree {
public:
    TreeNode<T>* root;

    BinaryTree<T>(const std::vector<TreeNode<T>*>& ListOfNodes) : root(createBinaryTree(ListOfNodes)){}

    TreeNode<T>* createBinaryTree(const std::vector<TreeNode<T>*>& ListOfNodes) {
        if (ListOfNodes.empty()) {
            return nullptr;
        }

        TreeNode<T>* root = new TreeNode<T>(ListOfNodes[0]->data);

        std::queue<TreeNode<T>*> q;
        q.push(root);

        int i = 1;
        while (i < ListOfNodes.size()) {
            TreeNode<T>* curr = q.front();
            q.pop();

            if (ListOfNodes[i] != nullptr) {
                curr->left = new TreeNode<T>(ListOfNodes[i]->data);
                q.push(curr->left);
            }

            i++;

            if (i < ListOfNodes.size() && ListOfNodes[i] != nullptr) {
                curr->right = new TreeNode<T>(ListOfNodes[i]->data);
                q.push(curr->right);
            }

            i++;
        }

        return root;
    }
};
