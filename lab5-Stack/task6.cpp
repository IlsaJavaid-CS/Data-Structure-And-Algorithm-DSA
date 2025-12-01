#include <iostream>
#include <string>
using namespace std;

#define SIZE 100
class Stack {
private:
    char arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string exp) {
    Stack s;
    string result = "";

    for (char c : exp) {
        if (isalnum(c)) result += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                result += s.pop();
            s.pop(); // remove '('
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                result += s.pop();
            s.push(c);
        }
    }

    while (!s.isEmpty()) result += s.pop();
    return result;
}

int main() {
    string infix = "A+(B*C-(D/E))";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
