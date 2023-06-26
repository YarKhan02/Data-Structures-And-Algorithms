#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    private:
        ListNode* head;

    public:
        SinglyLinkedList() {
            head = nullptr;
        }

        void insertNodeAtEnd(int data) {
            if (head == nullptr) {
                head = new ListNode(data);
            }
            else{
                ListNode* newNode = new ListNode(data);
                ListNode* current = head;

                while (current->next != nullptr){
                    current = current->next;
                }
        
                current->next = newNode;
            }
        }

        void deleteKey(int n) {
            ListNode* current = head;
            ListNode* prev = nullptr;

            if ((current != nullptr) && (current->data == n)) {
                head = current->next;
                return;
            }

            while ((current != nullptr) && (current->data != n)) {
                prev = current;
                current = current->next;
            }
                
            if (current == nullptr) return;
                
            prev->next = current->next;
        }

        void display() {
            ListNode* current = head;

            while(current != nullptr) {
                cout << current->data << " ";
                current = current->next; 
            }
        }
};

int main() {
    SinglyLinkedList sll;

    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < 20; i++) {
        sll.insertNodeAtEnd(rand() % (10 - 0 + 1) + 0);
    }

    sll.display();
    sll.deleteKey(3);
    cout << endl;
    sll.display();
}