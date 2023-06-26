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

        bool detectingCycle() {
            ListNode* fastPtr = head;
            ListNode* slowPtr = head;
            
            while ((fastPtr != nullptr) && (fastPtr->next != nullptr)) {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
                if (slowPtr == fastPtr) {
                    return true;
                }
            }
            return false;
        }

        void removeLoop(ListNode* slowPtr) {
            ListNode* temp = head;

            while (slowPtr->next != temp->next) {
                slowPtr = slowPtr->next;
                temp = temp->next;
            }
            slowPtr->next = nullptr;
        }

        ListNode* getNode(ListNode* slowPtr) {
            ListNode* temp = head;

            while (slowPtr != temp) {
                slowPtr = slowPtr->next;
                temp = temp->next;
            }
            return temp;
        }

        void detectStartNode() {
            ListNode* fastPtr = head;
            ListNode* slowPtr = head;
            ListNode* node = nullptr;

            while ((fastPtr != nullptr) && (fastPtr->next != nullptr)) {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
                if (slowPtr == fastPtr) {
                    node = getNode(slowPtr);
                    removeLoop(slowPtr);
                    break;
                }
            }
            cout << "Starting node of a loop: " << node;
        }


        void display() {
            ListNode* current = head;

            while(current != nullptr) {
                cout << current->data << " ";
                current = current->next; 
            }
        }
};
