#include<iostream>
using namespace std;
void selectionSort(int arr[] , int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n ; j++)
        {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
            swap(arr[i] , arr[minIndex]);
        }
        
    }
    
}
void takeArray(int arr[], int &n ){
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
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
    int n , arr[100];
    //tum ankhon me to dekho
    takeArray( arr , n);
    selectionSort(arr , n );
    printArray(n , arr);
    return 0;
}