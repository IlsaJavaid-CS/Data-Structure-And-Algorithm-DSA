#include <iostream>
using namespace std;

class Node {
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
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    bool exists(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }


// why we used these parameters 

//  I added parameters because the function needs two input lists to work with.

// I used references (&) for efficiency (no copying of entire lists).

// I made them static because they act on two external lists, not the current object.

    static SinglyLinkedList getUnion(SinglyLinkedList& list1, SinglyLinkedList& list2) {
        SinglyLinkedList result; 
        Node* temp = list1.head;
        while (temp) {
            result.insertAtEnd(temp->data);
            temp = temp->next;
        }

 
        temp = list2.head;
        while (temp) {
            if (!result.exists(temp->data))
             {
                result.insertAtEnd(temp->data);
            }
            temp = temp->next;
        }

        return result;
    }

    static SinglyLinkedList getIntersection(SinglyLinkedList& list1, SinglyLinkedList& list2) 
    {
        SinglyLinkedList result;

        Node* temp1 = list1.head;

        while (temp1) {
            Node* temp2 = list2.head;
            while (temp2) {
                if (temp1->data == temp2->data && !result.exists(temp1->data)) {
                    result.insertAtEnd(temp1->data);
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return result;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list1, list2;

    list1.insertAtEnd(10);
    list1.insertAtEnd(15);
    list1.insertAtEnd(4);
    list1.insertAtEnd(20);


    list2.insertAtEnd(8);
    list2.insertAtEnd(4);
    list2.insertAtEnd(2);
    list2.insertAtEnd(10);


    SinglyLinkedList uni = SinglyLinkedList::getUnion(list1, list2);
    SinglyLinkedList inter = SinglyLinkedList::getIntersection(list1, list2);

    cout << "Union: ";
    uni.display();

    cout << "Intersection: ";
    inter.display();

    return 0;
}
