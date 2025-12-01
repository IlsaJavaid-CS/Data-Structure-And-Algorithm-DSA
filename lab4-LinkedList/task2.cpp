#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int val) {
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
        if (!head)  // check for the empty node
        { 
            head = newNode;
             return; 
        }

        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
             temp->next = newNode; // adding temp at the end
        
    }

    bool detectLoop()
    {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next)
         {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) // loop detection condition
                return true;
        }

        return false;
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
    list.insertAtEnd(60);
    // list.insertAtEnd(70);
    
    list.head->next->next->next->next->next = list.head->next->next;

    if (list.detectLoop())
        cout << "Loop detected!\n";
    else
        cout << "No loop found.\n";

    return 0;
}
