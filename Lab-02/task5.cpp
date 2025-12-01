#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
 {
    for (int i = 0; i < n - 1; i++)
     {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
 {

    int arr[] = {10, 4, 2, 7, 9, 11, 3};
    int n = 7;
    int k = 3; // 3rd smallest


    bubbleSort(arr, n);

    cout << k << "rd smallest element is: " << arr[k - 1];

    return 0;
}
