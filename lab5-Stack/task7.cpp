#include <iostream>
#include <string>
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
};

int evaluatePostfix(string exp) {
    Stack s;
    for (char c : exp) {
        if (c >= '0' && c <= '9') s.push(c - '0');
        else if (c == ' ') continue;
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix = "53+82-*";  // (5+3)*(8-2)
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
