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

        void insert_node_at_position(int data, int position) {
            Node* new_node = new Node(data);

            if (position == 0) {
                new_node->prev = head->prev;
                new_node->next = head;
                head->prev->next = new_node;
                head->prev = new_node;
                head = new_node;
            }
            else {
                int count = 0;
                Node* current = head;

                while ((current->next != head) && (count < position - 1)) {
                    current = current->next;
                    count++;
                }

                if ((count == position - 1) && (current->next == head)) {
                    new_node->prev = head->prev;
                    new_node->next = head;
                    head->prev->next = new_node;
                    head->prev = new_node;
                    return;
                }

                if (current->next == head) {
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
    cll.insert_node_at_position(3, 3);
    cll.display();
    // cll.display_reverse();
}