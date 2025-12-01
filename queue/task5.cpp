#include <iostream>
#include <deque>
using namespace std;

void maxInWindow(int arr[], int n, int k)
 {
    deque<int> dq;  // stores indices of useful elements
 for (int i = 0; i < n; i++)
     {
        // remove out-of-window indices
    while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();

        // remove smaller elements
        while (!dq.empty() && arr[dq.back()] < arr[i])
          
        dq.push_back(i);

        // print max for each full window
        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }

    cout << endl;
}

int main()
 {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = 8, k = 3;
    cout << "Maximums in every window: ";
    maxInWindow(arr, n, k);
    return 0;
    
}
