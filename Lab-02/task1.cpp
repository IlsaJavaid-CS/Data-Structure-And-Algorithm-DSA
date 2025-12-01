#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 6, 7, 10};
    int n = 6;
    int low = 1, high = 10;

    cout << "Missing numbers: ";
    for (int i = low; i <= high; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) cout << i << " ";
    }
    return 0;
}
