#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int num = q.size();
    int half = num / 2;
    queue<int> firstHalf;

    // move first half to another queue
    for (int i = 0; i < half; i++) 
    {
        firstHalf.push(q.front());
        q.pop();
    }

    // interleave both halves
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
 {
    queue<int> q;
    q.push(2); q.push(4); q.push(3); q.push(1);

    cout << "Original queue: 2 4 3 1" << endl;
    interleave(q);
    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
