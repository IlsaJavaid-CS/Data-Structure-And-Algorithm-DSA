#include <iostream>
using namespace std;

int main()
 {

    int roll[] = {101, 102, 103, 104, 105};
    int marks[] = {80, 75, 80, 60, 75};
    int n = 5;


    for (int i = 0; i < n - 1; i++)
     {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (marks[j] < marks[j + 1] ||
               (marks[j] == marks[j + 1] && roll[j] > roll[j + 1]))

                {

                swap(marks[j], marks[j + 1]);
                swap(roll[j], roll[j + 1]);
            }
        }
    }

    cout << "Roll\tMarks\n";
    
    for (int i = 0; i < n; i++)
        cout << roll[i] << "\t" << marks[i] << endl;

    return 0;
}
