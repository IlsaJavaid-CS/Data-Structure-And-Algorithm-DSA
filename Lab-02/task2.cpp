#include <iostream>
using namespace std;

int main() 
{
    int votes[] = {1, 4, 2, 1, 3, 2, 4, 1};
    int n = 8;
    int maxVal = 4;

    int count[10] = {0}; // assuming IDs ≤ 9

    for (int i = 0; i < n; i++)
        count[votes[i]]++;

    cout << "Vote Count:\n";


    for (int i = 1; i <= maxVal; i++)
    {
        
        cout << "Candidate " << i << ": " << count[i] << " votes\n";
    }
    return 0;

}
