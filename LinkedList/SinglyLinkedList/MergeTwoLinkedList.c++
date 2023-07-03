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

        void merge(SinglyLinkedList* l1, SinglyLinkedList* l2) {
            ListNode* list_1 = l1->head;
            ListNode* list_2 = l2->head;
            ListNode* temp = new ListNode(0);

            while ((list_1 != nullptr) && (list_2 != nullptr)) {
                if (list_1->data < list_2->data) {
                    temp->next = list_1;
                    list_1 = list_1->next;
                }
                else{
                    temp->next = list_2;
                    list_2 = list_2->next;
                }
                temp = temp->next;
            }

            if (list_1 == nullptr) {
                temp->next = list_2;
            }
            else{
                temp->next = list_1;
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
    SinglyLinkedList sll1, sll2;

    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < 5; i++) {
        sll1.insertNodeAtEnd(rand() % (10 - 0 + 1) + 0);
    }

    for (int i = 0; i < 5; i++) {
        sll2.insertNodeAtEnd(rand() % (10 - 0 + 1) + 0);
    }

    cout << "First List\n";
    sll1.display();

    cout << "Second List\n";
    sll2.display();

    sll1.merge(&sll1, &sll2);
}