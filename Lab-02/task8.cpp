#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {  
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1; 
}


void quickSort(int arr[], int low, int high)
 {
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   
        quickSort(arr, pi + 1, high);  
    }
}

int main()
 {
    int transactions[] = {1200, 50, 330, 75, 8900, 600, 25};
    int n = 7;

   
    quickSort(transactions, 0, n - 1);

    cout << "Transaction Alerts:"<<endl;

    for (int i = 0; i < n; i++)
     {
        cout << transactions[i] << " -> ";
        if (transactions[i] > 1000)
            cout << "Suspicious"<<endl;
        else
            cout << " Normal"<<endl;
    }

    return 0;
}
