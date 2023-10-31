#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this -> data = data;
            this -> left = nullptr;
            this -> right = nullptr;
        }
};
class BinaryTree {
    private:
        TreeNode* root;

    public:
        BinaryTree () {}
        
        void create_tree() {
            TreeNode* first = new TreeNode(1);
            TreeNode* second = new TreeNode(2);
            TreeNode* third = new TreeNode(3);
            TreeNode* forth = new TreeNode(4);
            TreeNode* fifth = new TreeNode(5);
            TreeNode* sixth = new TreeNode(6);
            TreeNode* seventh = new TreeNode(7);

            root = first;
            first->left = second;
            first->right = third;
            second->left = forth;
            second->right = fifth;
            third->left = sixth;
            third->right = seventh;
        }

        void pre_order_recursive(TreeNode* root) {
            if (root == nullptr) {
                return;
            }
            cout << root->data << " ";
            pre_order_recursive(root->left);
            pre_order_recursive(root->right);
        }

        void in_order_recursive(TreeNode* root) {
            if (root == nullptr) {
                return;
            }
            in_order_recursive(root->left);
            cout << root->data << " ";
            in_order_recursive(root->right);
        }

        void post_order_recursive(TreeNode* root) {
            if (root == nullptr) {
                return;
            }
            in_order_recursive(root->left);
            in_order_recursive(root->right);
            cout << root->data << " ";
        }

        void pre_order_iterative() {
            stack<TreeNode*> stack;
            stack.push(root);

            while (!stack.empty()) {
                TreeNode* current = stack.top();
                stack.pop();
                cout << current -> data << " ";
                if (current -> right != nullptr) {
                    stack.push(current -> right);
                }
                if (current -> left != nullptr) {
                    stack.push(current -> left);
                }
            }
        }

        void in_order_iterative() {
            stack<TreeNode*> stack;
            TreeNode* current = root;

            while (!stack.empty() || current != nullptr) {
                if (current != nullptr) {
                    stack.push(current);
                    current = current->left;
                }
                else {
                    current = stack.top();
                    stack.pop();
                    cout << current->data << " ";
                    current = current->right;
                }
            }
        }

        TreeNode* root_node() {
            return root;
        }
};

int main() {
    BinaryTree bt;
    bt.create_tree();
    TreeNode* r = bt.root_node();
    // bt.pre_order_recursive(r);
    // bt.pre_order_iterative();
    // bt.in_order_recursive(r);
    // bt.in_order_iterative();
    bt.post_order_recursive(r);
    cout << endl;
    // bt.in_order_iterative();
}