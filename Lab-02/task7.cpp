#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
 {
    for(int i = 0; i < size - 1; i++)
    
    {
        for(int j = 0; j < size - i - 1; j++)
         {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void printTime(int time)
 {
    int hour = time / 100;
    int min = time % 100;
    if(hour < 10) cout << "0"; 
    cout << hour << ":";
    if(min < 10) cout << "0";  
    cout << min;
}

int main()
 {
    int flights[] = {930, 745, 1230, 1100, 1545, 600};
    int size = 6;


    bubbleSort(flights, size);

  
    cout << "Sorted flight times: ";
    for(int i = 0; i < size; i++)
     {
        printTime(flights[i]);
        cout << " ";
    }


    cout << "Earliest flight: "<<endl;
    printTime(flights[0]);

    cout << "Latest flight: "<<endl;
    printTime(flights[size - 1]);

    return 0;
}
