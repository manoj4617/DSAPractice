#include <iostream>
#include <string>
#include "tree.h"
#include <algorithm>

using namespace std;

int m = 0;
const string MARKER = "M";


/**
 * This function is a helper for the Serialize function. It is a recursive
 * function that takes a pointer to a Node and a reference to a vector of
 * strings as arguments. It traverses the tree in a pre-order fashion and
 * inserts the string representation of each node into the vector of strings.
 *
 * If the current node is a nullptr, it inserts a string of the form "M<n>" into
 * the vector, where n is the current value of the global variable m, and then
 * increments m. This is used to mark the position of a nullptr in the stream.
 *
 * If the current node is not a nullptr, it recursively calls itself on the
 * left and right subtrees of the current node.
 */
void SerailizeHelper(Node* root, vector<string>& stream){
    if (root == nullptr) {
        // If the current node is a nullptr, insert a string of the form "M<n>"
        // into the vector, where n is the current value of the global variable
        // m, and then increment m. This is used to mark the position of a nullptr
        // in the stream.
        stream.push_back("M" + to_string(m));
        m++;
        return;
    }

    // If the current node is not a nullptr, recursively call this function on
    // the left and right subtrees of the current node.
    stream.push_back(to_string(root->data));
    SerailizeHelper(root->left_child, stream);
    SerailizeHelper(root->right_child, stream);
}

vector<string> Serialize(Node* root){
    vector<string> stream;
    SerailizeHelper(root, stream);
}

/**
 * This function is a helper for the Deserialize function. It takes a reference
 * to a vector of strings as an argument, and returns a pointer to a Node.
 *
 * The vector of strings is a stream of serialized tree nodes, where each node
 * is represented as a string. The string representation of a node is either
 * the value of the node (if the node is not a nullptr), or a special marker
 * string "M<n>" (if the node is a nullptr), where n is a unique integer that
 * marks the position of the node in the stream.
 *
 * This function pops the last element of the stream, and creates a new node with
 * the value represented by the popped string. If the popped string is the
 * special marker string, it returns nullptr instead.
 *
 * Then, it recursively calls itself on the left and right subtrees of the
 * created node, and assigns the return values to the left and right child
 * pointers of the created node.
 *
 * Finally, it returns the created node.
 */
Node* DeserializeHelper(vector<string>& stream){
    string val = stream.back();
    stream.pop_back();
    if(val.substr(0,1) == MARKER){
        // If the popped string is the special marker string, return nullptr
        return nullptr;
    }
    Node* tree = new Node(stoi(val));
    // Recursively create the left subtree
    tree->left_child = DeserializeHelper(stream);
    // Recursively create the right subtree
    tree->right_child = DeserializeHelper(stream);
    return tree;
}

Tree* Deserialize(vector<string>& stream){
    reverse(stream.begin(), stream.end());
    Tree* tree = new Tree();
    tree->root = DeserializeHelper(stream);
    return tree;
}

void PrintStream(vector<string>& stream){
    for(const string& s : stream){
        cout << s << " ";
    }
}

int main(){
    Tree* tree = new Tree();
    tree->create_tree();
    vector<string> res = Serialize(tree->root);
    PrintStream(res);
    Tree* deTree = Deserialize(res);
    deTree->pre_order(deTree->root);
}