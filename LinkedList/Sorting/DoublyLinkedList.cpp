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

        void bubble_sort() {
            Node* current = head;
            int s;
            while (current != nullptr) {
                Node* n = head;
                while (n->next != nullptr) {
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
            Node* sorted = nullptr;
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                if (!sorted || current->data <= sorted->data) {
                    current->next = sorted;
                    sorted = current;
                } 
                else {
                    Node* temp = sorted;
                    while (temp->next && temp->next->data < current->data) {
                        temp = temp->next;
                    }
                    current->next = temp->next;
                    temp->next = current;
                }
                current = next;
            }
            head = sorted;
        }

        void selection_sort() {
            int value;
            Node* current = head;
            while (current != nullptr) {
                Node* flow = current->next;
                Node* least = current;
                while (flow != nullptr) {
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

            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    DoublyLinkedList dllb, dlli, dlls;
    
    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < 10; i++) {
        dllb.insert_node_at_end(rand() % (25 - 0 + 1) + 0);
    }

    cout << "Origianl Linked List" << endl;
    dllb.display();

    cout << "Bubble Sort" << endl;
    dllb.bubble_sort();
    dllb.display();

    for (int i = 0; i < 10; i++) {
        dlli.insert_node_at_end(rand() % (25 - 0 + 1) + 0);
    }

    cout << "\nOrigianl Linked List" << endl;
    dlli.display();

    cout << "Insertion Sort" << endl;
    dlli.insertion_sort();
    dlli.display();

    for (int i = 0; i < 10; i++) {
        dlls.insert_node_at_end(rand() % (25 - 0 + 1) + 0);
    }

    cout << "\nOrigianl Linked List" << endl;
    dlls.display();

    cout << "Selection Sort" << endl;
    dlls.selection_sort();
    dlls.display();
}