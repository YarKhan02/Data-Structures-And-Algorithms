#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList () {
            this->head = nullptr;
        }

        void insert_node_at_end(int data) {
            if (head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* current = head;

                while (current->next != nullptr) {
                    current = current->next;
                }

                current->next = new Node(data);
            }
        }

        void modify () {
            Node* current = head;
            Node* odd = nullptr;
            Node* even = nullptr;
            Node* temp_even = nullptr;
            Node* temp_odd = nullptr;

            while (current != nullptr) {
                if ((current->data % 2) == 0) {
                    if (even == nullptr) {
                        even = current;
                        temp_even = even;
                    }
                    else{
                        temp_even->next = current;
                        temp_even = temp_even->next; 
                    }
                }
                else {
                    if (odd == nullptr) {
                        odd = current;
                        temp_odd = odd;
                    }
                    else{
                        temp_odd->next = current;
                        temp_odd = temp_odd->next; 
                    }
                }
                current = current->next;
            }
            if (odd == nullptr) {
                head = even;
            }
            if (even == nullptr) {
                head = odd;
            }
            head = even; 
            temp_even->next = odd;
            temp_odd->next = nullptr;
        }

        void display () {
            Node* current = head;

            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
        }
};

int main () {
    LinkedList ll;

    ll.insert_node_at_end(17);
    ll.insert_node_at_end(15);
    ll.insert_node_at_end(8);
    ll.insert_node_at_end(12);
    ll.insert_node_at_end(10);
    ll.insert_node_at_end(5);
    ll.insert_node_at_end(4);
    ll.insert_node_at_end(1);
    ll.insert_node_at_end(7);
    ll.insert_node_at_end(6);
    ll.modify();
    ll.display();
}