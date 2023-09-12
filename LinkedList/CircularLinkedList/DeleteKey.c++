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

class CircularLinkedList {
    private:
        Node* head;

    public:
        CircularLinkedList() {
            this->head = nullptr;
        }

        void insert_node_at_end(int data) {
            if (head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* new_node = new Node(data);
                Node* current = head;

                while((current->next != nullptr) && (current->next != head)) {
                    current = current->next;
                }

                current->next = new_node;
                new_node->prev = current;
                new_node->next = head;
                head->prev = new_node;
            }
        }

        void delete_key(int data) {
            if (head->data == data) {
                head->next->prev = head->prev;
                head->prev->next = head->next;
                head = head->next;
                return;
            }

            Node* current = head;

            while ((current->next != head) && (current->data != data)) {
                current = current->next;
            }

            if ((current->next == head) && (current->data == data)){
                current->prev->next = current->next;
                return;
            }

            if (current->next == head) {
                cout << "Invalid key" << endl;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        void display() {
            Node* current = head;

            while (current->next != head) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << current->data << endl;
        }
        
        void display_reverse() {
            Node* current = head;

            while (current->prev != head) {
                cout << current->data << " ";
                current = current->prev;
            }
            cout << current->data << endl;
        }
};

int main() {
    CircularLinkedList cll;
    cll.insert_node_at_end(0);
    cll.insert_node_at_end(2);
    cll.insert_node_at_end(5);
    cll.insert_node_at_end(7);
    cll.insert_node_at_end(1);
    cll.delete_key(1);
    cll.display();
    // cll.display_reverse();
}