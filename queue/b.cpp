#include <iostream>
using namespace std;

int firstOccur(int arr[], int n, int x) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == x) {
            res = mid;
            high = mid - 1; // search left side
        } else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return res;
}

int lastOccur(int arr[], int n, int x) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == x) {
            res = mid;
            low = mid + 1; // search right side
        } else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return res;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 2;
    cout << "First index: " << firstOccur(arr, n, x)
         << "\nLast index: " << lastOccur(arr, n, x);
    return 0;
}
