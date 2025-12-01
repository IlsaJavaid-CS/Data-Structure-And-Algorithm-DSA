#include <iostream>
#include <queue>
using namespace std;

void firstNegativeInWindow(int arr[], int n, int k)
 {
    
    queue<int> q;  // stores indices of negative numbers

    // Process first window
    for (int i = 0; i < k; i++)
        if (arr[i] < 0) q.push(i);

    // Process remaining windows
    for (int i = k; i < n; i++)
     {
        // print first negative of previous window
        if (!q.empty()) cout << arr[q.front()] << " ";
        else cout << 0 << " ";

        // remove elements outside this window
        while (!q.empty() && q.front() <= i - k)
            q.pop();


        // add current element if negative
        if (arr[i] < 0)
            q.push(i);
    }

    // last window
    if (!q.empty()) cout << arr[q.front()] << endl;
    else cout << 0 << endl;
}

int main()
 {

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = 8, k = 3;
    cout << "First negative number in every window: ";
    firstNegativeInWindow(arr, n, k);
    return 0;

}
