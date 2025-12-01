#include <iostream>
using namespace std;

// these are local variables used accross the whole program....
int rows;
int columns;
int matrix[20][20];

// I made this takeMatrix function to easily take and display the matrix to user.....
void takeMatrix()
{
    // this loop is just to ensure that user must enter the square matrix only....
    do
    {
        
        cout << "Enter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> columns;
        if (rows != columns)
        {
            cout << "Number of rows and columns should be same....";
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> columns;
        }
    } while (rows != columns);

    // taking matrix as input from the user....
    
    cout << "Enter the matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // displaying the matrix....

    cout << "The matrix is: " << endl;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

// function to sum the upper diagonal matrix...

int sumOfUpperDiagonal(int matrix[20][20]){
    int result=0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if ( i<=j){
               result+=matrix[i][j];
            } 
        }
        
        
    }
    return result;
    
}

// function to sum the lower diagonal matrix...

int SumOfLowerDiagonal(int matrix[20][20]){
    int result=0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i >=j)
            {
                result+=matrix[i][j];
            }
            
        }
        
    }
    return result;
    
}

int main()
{
    takeMatrix();
    cout<<"Sum of Upper Triangular Matrix is: "<<sumOfUpperDiagonal(matrix)<<endl;
     cout<<"Sum of Upper Triangular Matrix is: "<<SumOfLowerDiagonal(matrix)<<endl;
    return 0;
}

//end ....