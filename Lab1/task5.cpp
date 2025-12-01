#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[100];
    cout<<"Enter the elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if(arr[i]  != 0){    // this if statement is checking the non-zero numbers and skipping them....
            arr[index] = arr[i];
            index++;
        }
    }


    while(index < size){     // adding zeros to the remaining places...
        arr[index] = 0;
        index++;
    }


    cout<<"New array: ";
    for (int i = 0; i < size; i++)
    {
       cout<<arr[i];
    }
    cout<<endl;
    return 0;
    
}



