#include <iostream>
using namespace std;

#define MAX 20   // maximum number of customers

// Simple circular queue for storing customer IDs
class Queue {
    int front, rear;
    int arr[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)  // if queue is empty
            front = 0;

        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        int val = arr[front];

        if (front == rear)
            front = rear = -1;  // queue becomes empty
        else
            front = (front + 1) % MAX;

        return val;
    }
};

// Structure to store customer details
struct Customer {
    int id;
    int arrival;
    int service;
    int start;
    int finish;
    int wait;
};

int main()
 {
    int number;
    cout << "Enter the Number of Customers: ";
    cin >> number;

    Customer c[MAX];
    Queue q;

    cout << "\nEnter Arrival and Service times for each customer:\n";
    for (int i = 0; i < number; i++) {
        c[i].id = i + 1;
        cout << "Customer " << c[i].id << " Arrival time: ";
        cin >> c[i].arrival;
        cout << "Customer " << c[i].id << " Service time: ";
        cin >> c[i].service;
        q.enqueue(c[i].id);
    }

    int currentTime = 0;
    float totalWait = 0;

    cout << "\nID\tArrival\tService\tStart\tFinish\tWaiting\n";
    cout << "---------------------------------------------\n";

    while (!q.isEmpty()) {
        int id = q.dequeue();
        int i = id - 1;

        // If teller is idle until customer arrives
        if (currentTime < c[i].arrival)
            currentTime = c[i].arrival;

        c[i].start = currentTime;
        c[i].finish = c[i].start + c[i].service;
        c[i].wait = c[i].start - c[i].arrival;

        totalWait += c[i].wait;
        currentTime = c[i].finish;

        cout << c[i].id << "\t"
             << c[i].arrival << "\t"
             << c[i].service << "\t"
             << c[i].start << "\t"
             << c[i].finish << "\t"
             << c[i].wait << "\n";
    }

    cout << "\nTotal Customers: " << number;
    cout << "\nAverage Waiting Time: " << totalWait / number << " minutes";
    cout << "\nTotal Simulation Time: " << currentTime << " minutes\n";

    return 0;
}
