#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val)   // parametrized constructor
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

        Node* temp = head; // new temporary node
        while (temp -> next)
            temp = temp -> next;    // each time assigning a value of temp to the next pointer
        temp -> next = newNode;  
    }

    void findMiddle() {
        Node* slow = head; // will move one node forward
        Node* fast = head; // will move two nodes at a time

        while (fast != NULL && fast->next != NULL) 
        {
            slow = slow->next; // one at a time
            fast = fast->next->next; // two at a time
        }

        cout << "Middle Node: " << slow -> data << endl;
    }

    void display()
     {
        Node* temp = head;
        while (temp)
         {
            cout << temp->data;
            if (temp->next){
                    cout << " -> ";
            }
           
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
 {
    SinglyLinkedList list;
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.insertAtEnd(25);
    list.insertAtEnd(30);

    cout << "List: ";
    list.display();
    list.findMiddle();

    return 0;
}
