#include <iostream>
using namespace std;

int main()
 {

    int arr[] = {2, -3, 4, -1, -7, 8, 9, -5};
    int n = 8;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j) swap(arr[i], arr[j]);
            j++;
        }
    }

    cout << "After separation: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        
    return 0;
}
