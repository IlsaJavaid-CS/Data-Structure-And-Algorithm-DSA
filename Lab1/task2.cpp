#include<iostream>
using namespace std;
int minimun(int arr[] , int startingIndex , int endingIndex) {
        int minIndex = startingIndex;
        for (int i = startingIndex + 1 ; i <= endingIndex; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }
        return minIndex;
    }
int takeInput()
{
    int size;
    int elements;
    int startingIndex;
    int endingIndex;
    int arr[20];
    cout << "Enter the size of array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        cout << " , ";
    }
    cout<<"Enter the Starting Index: ";
    cin>>startingIndex;
    cout<<"Enter the ending Index: ";
    cin>>endingIndex;
    int minIndex = minimun(arr , startingIndex, endingIndex);
    cout<<"The minimum element is: "<<arr[minIndex] <<" at index "<<minIndex<<endl;
    return 0;
}
int main()
{
    takeInput();
}