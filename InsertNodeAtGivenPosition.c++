#include <iostream>
#include <cstdlib>
#include <ctime>

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

        void insertNodeAtGivenPosition(int data, int n) {
            if (n == 0) {
                if (head == nullptr) {
                    head =  new ListNode(data); 
                }
                else{
                    ListNode* newNode = new ListNode(data);
                    newNode->next = head;
                    head = newNode;
                }
            }
            else{
                ListNode* newNode = new ListNode(data);
                ListNode* currentNode = head;
                ListNode* prevNode = nullptr;

                int count = 0;

                while (count != n) {
                    currentNode = currentNode->next;
                    if (count == n - 1) {
                        prevNode = currentNode;
                    }
                    count++;
                }

                if (currentNode->next != nullptr) {
                    newNode->next = currentNode->next;
                    prevNode->next = newNode;
                }
                else {
                    prevNode->next = newNode;
                }
            }
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

    for (int i = 0; i < 5; i++) {
        sll.insertNodeAtEnd(rand() % (10 - 0 + 1) + 0);
    }

    for (int i = 0; i < 5; i++) {
        sll.insertNodeAtGivenPosition(rand() % (10 - 0 + 1) + 0, rand() % (5 - 0 + 1) + 0);
    }

    sll.display();
}