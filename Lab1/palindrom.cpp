#include<iostream>
using namespace std;
bool isPalindrom(string s , int l , int r){
    if(l>=r) return true; //base case
    if(s[l] != s[r]){
        return false;
    }
    return isPalindrom(s , l+1 , r-1);
}
int main(){
    string word = "madam";
    cout<< (isPalindrom(word , 0 , word.size() -1) ? "Palindrom" : "Not Palindrom")<<endl;
    return 0;

}