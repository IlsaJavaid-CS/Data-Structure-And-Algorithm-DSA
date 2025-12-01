#include <iostream>
#include <string>
using namespace std;


#define SIZE 100
class Stack {
private:
    char arr[SIZE];
    int top;
public:
    Stack()
     { 
        top = -1;
     }
    void push(char c)
     {
         if (top < SIZE - 1)
          arr[++top] = c;
         }
    char pop()
     { 
        return (top >= 0) ? arr[top--] : '\0'; 
    }
    bool isEmpty()
     { 
        return top == -1;
     }
};


void reverseWords(string str) {
    Stack s;
    string result = "";


    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ')
         s.push(str[i]);
        else {
            while (!s.isEmpty()) result += s.pop();
            result += ' ';
        }
    }
    while (!s.isEmpty()) result += s.pop();

  
    Stack reverse;
    for (char c : result) 
    reverse.push(c);
    string finalRes = "";
    while (!reverse.isEmpty()) 
    finalRes += reverse.pop();

    cout << "Reversed Sentence:\n" << finalRes << endl;
}

int main()
 {
    string input = "I am from University of Engineering and Technology Lahore";
    reverseWords(input);
    return 0;
}
