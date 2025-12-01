#include<iostream>
using namespace std;
string removeSpace(string s, int i = 0){ 
    if(i == s.size()) return "";
    if(s[i] == ' ') return removeSpace(s , i+1);
    return s[i] + removeSpace(s , i+1);
}
int main(){
    cout<<removeSpace("Data Structure Lab") << endl;
    return 0;
}