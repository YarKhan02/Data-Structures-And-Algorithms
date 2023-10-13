#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    private:
        Node* head;

    public:
        SinglyLinkedList() {
            head = nullptr;
        }

        void insertNodeAtEnd(int data) {
            if (head == nullptr) {
                head = new Node(data);
            }
            else{
                Node* newNode = new Node(data);
                Node* current = head;

                while (current->next != nullptr){
                    current = current->next;
                }
        
                current->next = newNode;
            }
        }

        void bubble_sort() {
            int s;
            Node* current = head;
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

            while(current != nullptr) {
                cout << current->data << " ";
                current = current->next; 
            }
            cout << endl;
        }
};

int main() {
    SinglyLinkedList sllb, slli, slls;

    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < 10; i++) {
        sllb.insertNodeAtEnd(rand() % (25 - 0 + 1) + 0);
    }

    cout << "Origianl Linked List" << endl;
    sllb.display();

    cout << "Bubble Sort" << endl;
    sllb.bubble_sort();
    sllb.display();

    for (int i = 0; i < 10; i++) {
        slli.insertNodeAtEnd(rand() % (25 - 0 + 1) + 0);
    }

    cout << "\nOrigianl Linked List" << endl;
    slli.display();

    cout << "Insertion Sort" << endl;
    slli.insertion_sort();
    slli.display();

    for (int i = 0; i < 10; i++) {
        slls.insertNodeAtEnd(rand() % (25 - 0 + 1) + 0);
    }

    cout << "\nOrigianl Linked List" << endl;
    slls.display();

    cout << "Selection Sort" << endl;
    slls.selection_sort();
    slls.display();
}