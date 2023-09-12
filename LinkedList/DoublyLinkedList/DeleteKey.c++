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

        void delete_key(int data) {
            if (head->data == data) {
                head = head->next;
                head->prev = nullptr;
                return;
            }

            Node* current = head;

            while ((current != nullptr) && (current->data != data)) {
                current = current->next;
            }

            if (!current) {
                cout << "Invalid key" << endl;
                return;
            }

            if (current->next == nullptr) {
                current->prev->next = nullptr;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;
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
    dll.delete_key(1);
    dll.display();
}