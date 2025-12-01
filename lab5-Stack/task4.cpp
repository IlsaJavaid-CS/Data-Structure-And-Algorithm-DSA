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
    int peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
    int size() { return top + 1; }
};


int getMiddle(Stack &s, int curr, int n) {
    if (curr == n / 2) return s.peek();
    int temp = s.pop();
    int res = getMiddle(s, curr + 1, n);
    s.push(temp);
    return res;
}

int main() {
    Stack s;
    s.push(50); s.push(40); s.push(30); s.push(20); s.push(10);
    cout << "Middle Element: " << getMiddle(s, 0, s.size()) << endl;
    return 0;
}
