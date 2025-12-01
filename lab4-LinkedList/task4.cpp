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

    void rotate(int k) {
        if (!head || k == 0)
         return;

        Node* curr = head;
        int count = 1;
        while (count < k && curr) {
            curr = curr->next;
            count++;
        }

        if (!curr)
         return;

        Node* kthNode = curr;
        while (curr->next)
            curr = curr->next;

        curr->next = head;
        head = kthNode->next;
        kthNode->next = NULL;
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
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Original: ";
    list.display();

    list.rotate(2);

    cout << "Rotated by 2: ";
    list.display();

    return 0;
}
