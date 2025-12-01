#include<iostream>
using namespace std;
int main(){
    int mat[3][3] = {{1,3,5} , {3,6 ,7} , {0,7,5}};
    int rowSum[3] = {0} , colSum[3]={0};
    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 3; j++)
       {
         rowSum[i]+=mat[i][j];
         colSum[j]+=mat[i][j];
       }
       
    }
    cout<<"Row wise sum:";
    for (int i = 0; i < 3; i++)
    {
        cout<<rowSum[i]<<endl;
    }
    cout<<"Column-Wise sum: ";
    for (int j = 0; j < 3; j++)
    {
        cout<<colSum[j]<<endl;
        
    }
    return 0;
     
}