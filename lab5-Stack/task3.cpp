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

string removeDuplicates(string str) {
    Stack s;
    for (char c : str) {
        if (!s.isEmpty() && s.peek() == c)
            s.pop();
        else
            s.push(c);
    }

    string result = "";
    while (!s.isEmpty())
        result = s.pop() + result;

    return result;
}

int main() {
    string input = "aaabccddd";
    cout << "Input: " << input << endl;
    cout << "Output: " << removeDuplicates(input) << endl;
    return 0;
}
