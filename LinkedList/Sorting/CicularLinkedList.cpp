#include <iostream>
#include <ctime>

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

        void bubble_sort() {
            Node* current = head;
            int s;
            while (current->next != head) {
                Node* n = head;
                while (n->next != head) {
                    if (n->data > n->next->data) {
                        s = n->data;
                        n->data = n->next->data;
                        n->next->data = s;
                    }
                    n = n->next;
                }
                current = current->next;
            }
        }

        void insertion_sort() {
        
        }

        void selection_sort() {
            int value;
            Node* current = head;
            while (current->next != head) {
                Node* flow = current->next;
                Node* least = current;
                while (flow != head) {
                    if (flow->data < least->data) {
                        least = flow;
                    }
                    flow = flow->next;
                }
                value = least->data;
                least->data = current->data;
                current->data = value;
                current = current->next;
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
};

int main() {
    CircularLinkedList cllb, clli, clls;

    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < 10; i++) {
        cllb.insert_node_at_end(rand() % (100 - 0 + 1) + 0);
    }

    cout << "Origianl Linked List" << endl;
    cllb.display();

    cout << "Bubble Sort" << endl;
    cllb.bubble_sort();
    cllb.display();

    for (int i = 0; i < 10; i++) {
        clli.insert_node_at_end(rand() % (100 - 0 + 1) + 0);
    }

    cout << "\nOrigianl Linked List" << endl;
    clli.display();

    cout << "Insertion Sort" << endl;
    clli.insertion_sort();
    clli.display();

    for (int i = 0; i < 10; i++) {
        clls.insert_node_at_end(rand() % (100 - 0 + 1) + 0);
    }

    cout << "\nOrigianl Linked List" << endl;
    clls.display();

    cout << "Selection Sort" << endl;
    clls.selection_sort();
    clls.display();
}