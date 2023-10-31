#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class BST {
    private:
        Node* root;

    public:
        BST() {
            this->root = nullptr;
        }

        void search_insert_position(Node*& node, int data) {
            if (node == nullptr) {
                node = new Node(data);
                return;
            }

            if (data < node->data) {
                search_insert_position(node->left, data);
            }

            if (data > node->data) {
                search_insert_position(node->right, data);
            }
        }

        void insert_node(int data) {
            search_insert_position(root, data);
        }

        Node* search(Node* node, int key) {
            if ((!node) || (node->data == key)) {
                return node;
            }

            if (key > node->data) {
                search(node->right, key);
            }
            else {
                search(node->left, key);
            }
        }

        void search_key(int key) {
            Node* node = search(root, key);
            if (node) {
                cout << "Key Found!" << endl;
            }
            else {
                cout << "Key not in a tree" << endl;
            }
        }

        void display_tree(Node* node, int level) {
            if (node == nullptr) {
                return;
            }

            if ((node->left == nullptr) && (node->right == nullptr)) {
                for (int i = 0; i <= level; i++) {
                    cout << "\t";
                }
                cout << node->data << endl;
                return;
            }

            display_tree(node->right, level + 1);

            for (int i = 0; i < level; i++) {
                cout << "\t";
            }
            cout << node->data << endl;

            display_tree(node->left, level + 1);
        }

        void display() {
            display_tree(root, 0);
        }
};

int main() {
    BST bst;

    bst.insert_node(10);
    bst.insert_node(7);
    bst.insert_node(15);
    bst.insert_node(8);
    bst.insert_node(11);
    bst.insert_node(4);
    bst.insert_node(17);
    bst.insert_node(3);
    bst.insert_node(5);
    bst.insert_node(9);

    bst.search_key(5);

    bst.display();
}