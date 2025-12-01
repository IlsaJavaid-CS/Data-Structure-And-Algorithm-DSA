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

class SinglyLinkedList
 {
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

    void reverse()
     {
        Node* prev = NULL; // its convention to initialize both the previous and next pointers with NULL and current should be  on the head
        Node* curr = head;
        Node* next = NULL;
        // logic of reversing the list...!!
        while (curr)
         {
            next = curr->next; //  firstly moving next to currents next 
            curr->next = prev; // pehlay current k next ko previous k equal put karna ha takay address lost na ho
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display()
     {
        Node* temp = head;
        while (temp)
         {
            cout << temp -> data;
            if (temp->next) 
            cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
 {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}

