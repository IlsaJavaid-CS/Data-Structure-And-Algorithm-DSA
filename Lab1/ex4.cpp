// #include <iostream>
// using namespace std;
// int main(){
//     int size;
//     int arr[size] ;
//     int max=INT16_MAX;
//     cout<<"Enter the size of array:";
//     cin>>size;
//     cout<<"Enter the elements of array: ";
//     for (int i = 0; i < size; i++)
//     {
//         cout<<"ENter the elements: ";
//        cin>>arr[i];
    
//     if(arr[i]> max){
//         cout<<"Max Element"<< arr[i];
//     }
// }
// return 0;   
// }
#include<iostream>
using namespace std;
int findMax(int arr[] , int n){
    if(n == 1)
        return arr[0];
        return max(arr[n-1] , findMax(arr, n-1));
    
}
int main(){
    int arr[]= {1 , 3,6 ,7,0};
    cout<<"<Max Element"<< findMax(arr , 5)<<endl;
    return 0;
}