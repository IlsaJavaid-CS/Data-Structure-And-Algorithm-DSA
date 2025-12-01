#include <iostream>
using namespace std;

#define SIZE 100
class Stack {
private:
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
    int size() { return top + 1; }
    void display() {
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};


void deleteMiddle(Stack &s, int curr, int n) {
    if (curr == n / 2) { s.pop(); return; }
    int temp = s.pop();
    deleteMiddle(s, curr + 1, n);
    s.push(temp);
}

int main() {
    Stack s;
    s.push(50); s.push(40); s.push(30); s.push(20); s.push(10);
    cout << "Original Stack: "; s.display();
    deleteMiddle(s, 0, s.size());
    cout << "After Deleting Middle: "; s.display();
    return 0;
}
