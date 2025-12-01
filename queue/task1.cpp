#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k)
 {
    stack<int> st; //object of stack
    // Step 1: move first k elements into stack
    for (int i = 0; i < k && !q.empty(); i++)
     {
        st.push(q.front());
        q.pop();
    }

    // Step 2: push them back (reversed)
    while (!st.empty())
     {
        q.push(st.top());
        st.pop();
    }
    // Step 3: move remaining elements to back
    int rem = q.size() - k;
    for (int i = 0; i < rem; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() 
{
    queue<int> q;
    for (int i = 1; i <= 5; i++) q.push(i);
    int k = 3;

    cout << "Original queue: ";
    for (int i = 1; i <= 5; i++) cout << i << " ";
    cout << endl;

    reverseFirstK(q, k);

    cout << "After reversing first " << k << " elements: ";
    while (!q.empty())
     {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
