#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) 
{
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++)
     {
        string current = q.front();
        q.pop();
        cout << current << " ";
        q.push(current + "0");
        q.push(current + "1");
    }
    cout << endl;
}

int main()
 {
    int n = 4;
    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinary(n);
    return 0;
}
