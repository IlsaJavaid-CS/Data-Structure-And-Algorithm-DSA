#include <iostream>
using namespace std;

int main()
{
    int element = 0;

    int indices[20]; // small array to store indices...

    int count = 0;   // how many times we found the element....

    int arr[] = {22, 2, 1, 7, 11, 13, 5, 2, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

    // because size of array will give the total number of bytes like 5*4, so to just find elements divide with 4 or with any number of array index

    int size = sizeof(arr) / 4; // it will also work for size of array....

    cout << "Enter the element to be searched: ";

    cin >> element;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            indices[count] = i; // store the index...
            count++;
           
        }
    }

    if (count== 0)
    {
        cout<<"Element" << element <<" not found in the array..." <<endl;
    }

    else{
        cout<<"Element " << element <<" found at indices: ";
        for (int i = 0; i < count; i++)
        {
            cout<< indices[i] <<" ";
        }
        cout<<endl;
        
    }
    return 0;
    
}