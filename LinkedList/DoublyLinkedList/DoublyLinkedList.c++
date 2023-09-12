#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        } 
};

class DoublyLinkedList {
    private:
        Node* head;

    public:
        DoublyLinkedList() {
            this->head = nullptr;
        }

        void insert_node_at_start(int data) {
            if (head == nullptr) {
                head = new Node (data);
            }
            else {
                Node* new_node = new Node (data);
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        } 
        void display() {
            Node* current = head;

            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
        }
};

int main() {
    DoublyLinkedList dll;
    dll.insert_node_at_start(0);
    dll.insert_node_at_start(2);
    dll.insert_node_at_start(5);
    dll.insert_node_at_start(7);
    dll.insert_node_at_start(1);
    dll.display();
}