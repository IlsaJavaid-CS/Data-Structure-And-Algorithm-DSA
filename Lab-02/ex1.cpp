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
void bubbleSort(int n, int arr[] ){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
           if (arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
           }
        }
        
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
    int arr[100];
    int n ;
takeArray(arr, n);
bubbleSort(n , arr);
printArray(n , arr);
return 0;
}
