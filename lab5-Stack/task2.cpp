#include <iostream>
#include <string>
using namespace std;

#define SIZE 1000
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

bool isBalanced(string exp) {
    Stack s;
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    cout << "{[()]} → " << (isBalanced("{[()]}") ? "Balanced" : "Not Balanced") << endl;
    cout << "{[(])} → " << (isBalanced("{[(])}") ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
