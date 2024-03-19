#include<vector>

class Node{
    public:
        Node* left_child;
        int data;
        Node* right_child;
        Node* create_new_node(int data){
            Node *t = new Node();
            t->data = data;
            t->left_child = t->right_child = nullptr;
            return t;
        }
};

class Tree{
    public:
        Node* root;
        Tree(){root = NULL;}
        void create_tree();
        void pre_order(Node* p);
        void in_order(Node* p);
        void post_order(Node* p);
        void level_order(Node* p);
        int find_height(Node *p);

        void itr_pre_order(Node *p);
        void itr_in_order(Node *p);

        void left_view(Node* root);

};