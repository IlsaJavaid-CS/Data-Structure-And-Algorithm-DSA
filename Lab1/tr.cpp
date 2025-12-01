#include<iostream>
using namespace std;
int main(){
    int rows = 2;
    int cols = 3;
    int mat[2][3] = {{1,2,3} , {3,5,6}};
    int trans[3][2];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
           trans[j][i] = mat[i][j];
        }
        
    }
    cout<<"Original Matrix: "<< rows << "x" <<cols << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<mat[i][j]<< " ";

        }
        cout<<endl;
        
    }

    cout<<"Transpose of Matrix: "<< cols <<"x" <<rows<< "\n";
    
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout<<trans[i][j]<< " ";
        }
        cout<<endl;
    }
    
    return 0;
    

}