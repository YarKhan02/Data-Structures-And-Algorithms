#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
            this->next = nullptr;
        }
};

class Queue {
    private:
        Node* front;
        Node* rear;

    public:
        Queue() {
            this->front = nullptr;
            this->rear = nullptr;
        }

        void enqueue(Node* node) {
            if (isEmpty()) {
                front = node;
                rear = node;
            }
            else {
                rear->next = node;
                rear = node;
            }
        }

        Node* dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return nullptr;
            }

            Node* temp = front;
            front = front->next;
            return temp;
        }

        void printForward() {
            Node* current = front;
            cout << "Queue (Forward): ";
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        bool isEmpty() {
            return front == nullptr;
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

        void level_order_traversal() {
            if (!root) {
                return;
            }

            Queue q;
            q.enqueue(root);

            while (!q.isEmpty()) {
                Node* current = q.dequeue();

                cout << current->data << " ";

                if (current->left) {
                    q.enqueue(current->left);
                }

                if (current->right) {
                    q.enqueue(current->right);
                }
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

    bst.level_order_traversal();

    cout << endl << endl;

    bst.display();
}