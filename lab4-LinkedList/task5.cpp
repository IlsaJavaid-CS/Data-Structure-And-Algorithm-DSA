#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) 
    { 
        data = val;
         next = NULL;
         }
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList()
     { 
        head = NULL; 
    }

    void insertAtEnd(int val)
     {
        Node* newNode = new Node(val);
        if (!head)
         { 
            head = newNode;
             return; 
         }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void segregateEvenOdd() {
        Node* evenEnd = NULL;
        Node* evenStart = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* curr = head;

        while (curr)
         {
            int val = curr->data;
            if (val % 2 == 0) {
                if (!evenStart) {
                    evenStart = curr;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
            } else {
                if (!oddStart) {
                    oddStart = curr;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }
            curr = curr->next;
        }

        if (!evenStart || !oddStart)
            return;
//  merging two lists 
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        head = evenStart;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(17);
    list.insertAtEnd(15);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(6);

    cout << "Original: ";
    list.display();

    list.segregateEvenOdd();

    cout << "After Segregation: ";
    list.display();

    return 0;
}
