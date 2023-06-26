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

        void isPalindrome() {
            ListNode* current = head;
            vector<int> list;

            while (current != nullptr) {
                list.push_back(current->data);
                current = current->next;
            }

            int n = list.size() - 1;

            bool x = true;

            for (int j = 0; j < list.size(); j++){
                if (list[j] != list[n]) {
                    x = false;
                }
                n--;    
            }
            cout << "\n\nisPalindrome: " << x;
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

    // for (int i = 0; i < 5; i++) {
    //     sll.insertNodeAtEnd(rand() % (10 - 0 + 1) + 0);
    // }

    sll.insertNodeAtEnd(1);
    sll.insertNodeAtEnd(2);
    sll.insertNodeAtEnd(1);

    sll.display();

    sll.isPalindrome();
}