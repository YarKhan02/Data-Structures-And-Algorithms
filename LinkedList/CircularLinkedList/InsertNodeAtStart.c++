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

        void insert_node_at_start(int data) {
            if (head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* new_node = new Node(data);

                if (head->prev == nullptr) {
                    head->next = new_node;
                    new_node->prev = head;
                    new_node->next = head;
                    head->prev = new_node;
                    return;
                }

                new_node->prev = head->prev;
                new_node->next = head;
                head->prev->next = new_node;
                head->prev = new_node;
            }
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
    cll.insert_node_at_start(0);
    cll.insert_node_at_start(2);
    cll.insert_node_at_start(5);
    cll.insert_node_at_start(7);
    cll.insert_node_at_start(1);
    cll.display();
    cll.display_reverse();
}