#include <iostream>
using namespace std;
class Node
 {
public:
    int data;      
    Node* next;   

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;  
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

   
        if (head == nullptr) {
            head = newNode;
            return;
        }

 
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void removeDuplicates() {
        Node* current = head;

        while (current != NULL) {
            Node* runner = current; 
            
            while (runner->next != NULL) 
            {
                if (runner->next->data == current->data) {
              Node* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate; 
                }
                 else
                  {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.insertAtEnd(40);

    cout << "Original List: ";
    list.display();
    
    list.removeDuplicates();

    cout << "After Removing Duplicates: ";
    list.display();

    return 0;
}
