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

        void insertNodeSorted(int n) {
            ListNode* current = head;
            ListNode* temp = nullptr;
            
            while ((current != nullptr) && (current->data < n)){
                temp = current; 
                current = current->next;
            }
            ListNode* newNode = new ListNode(n);
            temp->next = newNode;
            newNode->next = current;
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

    // for (int i = 0; i < 20; i++) {
    //     sll.insertNodeAtEnd(rand() % (10 - 0 + 1) + 0);
    // }

    sll.insertNodeAtEnd(1);
    sll.insertNodeAtEnd(2);
    sll.insertNodeAtEnd(2);
    sll.insertNodeAtEnd(3);
    sll.insertNodeAtEnd(4);
    sll.insertNodeAtEnd(4);
    sll.insertNodeAtEnd(4);

    sll.display();
    sll.insertNodeSorted(3);
    cout << endl;
    sll.display();
}