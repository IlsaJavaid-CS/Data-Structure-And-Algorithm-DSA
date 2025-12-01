#include <iostream>
using namespace std;
int iterativePower( int a,  int b){
    int first = 1;
    for ( int i = 0; i < b; i++)
    {
        first*= a;
    }
    return first;
    
}
int main(){
    int a , b;
        cout<<"Enter 1st number:";
        cin>>a;
        cout<<"Enter 2nd number: ";
        cin>>b;
        cout<< a <<"^" << b<< "=" << iterativePower(a , b);
        return 0;
}

