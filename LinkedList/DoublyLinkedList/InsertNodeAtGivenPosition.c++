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

        void insert_node_at_end(int data) {
            if (head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* new_node = new Node(data);
                Node* current = head;

                while(current->next != nullptr) {
                    current = current->next;
                }

                current->next = new_node;
                new_node->prev = current;
            }
        } 

        void insert_node_at_position(int data, int position) {
            if (position < 0) {
                cout << "Invalid position" << endl; 
                return;
            }
            
            if (head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* new_node = new Node(data);

                if (position == 0) {
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                    return;
                }

                int count = 0;
                Node* current = head;

                while((count < position - 1) && (current->next != nullptr)) {
                    current = current->next;
                    count++;
                }

                if ((count == position - 1) && (current->next == nullptr)) {
                    current->next = new_node;
                    new_node->prev = current;
                    return;
                }

                if (!current->next) {
                    cout << "Invalid position" << endl;
                    return;
                }

                new_node->next = current->next;
                new_node->next->prev = new_node;
                current->next = new_node;
                new_node->prev = current;
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
    dll.insert_node_at_end(0);
    dll.insert_node_at_end(2);
    dll.insert_node_at_end(5);
    dll.insert_node_at_end(7);
    dll.insert_node_at_end(1);
    dll.insert_node_at_position(3, 4);
    dll.display();
}