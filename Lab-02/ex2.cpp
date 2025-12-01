#include<iostream>
using namespace std;
void takeArray(int arr[], int &n ){
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    } 
}
void insertionSort(int arr[] , int &n){
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key)
        {
           arr[j+1] = arr[i];
           j--;
        }
        arr[j+1] = key;
    }
}
void printArray(int n , int arr[]){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    
}
int main(){
    int n;
    int arr[100];
    takeArray(arr , n);
    insertionSort(arr, n);
    printArray(n, arr);
    return 0;
}