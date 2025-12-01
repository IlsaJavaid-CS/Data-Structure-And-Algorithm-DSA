#include<iostream>
using namespace std;
int recursivePower(int a, int b){
    if(b==0)
    return 1;
    return a*recursivePower(a , b-1);
}
int main(){
   int a = 4;
   int b = 5;
    cout<<a <<" ^ " <<b<<" = "<<recursivePower(2 , 7);
    return 0;

}