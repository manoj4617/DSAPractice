#include <iostream>
#include <vector>
#include <stack>

using namespace  std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * This function performs a pre-order traversal of an N-ary tree and returns a
 * vector of node values in the order that they were visited.
 *
 * @param root The root of the N-ary tree.
 *
 * @return A vector of node values in the order that they were visited.
 */
vector<int> preorder(Node* root) {
    if (!root) {
        // If the tree is empty, return an empty vector.
        return {};
    }

    vector<int> res;
    stack<Node*> st;
    st.push(root);

    /**
     * This loop will continue until all nodes in the tree have been visited.
     * It uses a stack to keep track of the nodes that need to be visited.
     */
    while (!st.empty()) {
        Node* node = st.top();
        res.push_back(node->val);

        /**
         * Pop the current node off the stack and add its children to the stack
         * in reverse order. This ensures that the children are visited in the
         * correct order (right to left).
         */
        st.pop();

        for (int i = node->children.size() - 1; i >= 0; --i) {
            st.push(node->children[i]);
        }
    }

    /**
     * Return the vector of node values in the order that they were visited.
     */
    return res;
}

int main(){
    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});

    vector<int> res = preorder(root);

    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }

    return 0;
}