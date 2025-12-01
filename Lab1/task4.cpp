#include <iostream>
using namespace std;
int main()
{
    int count = 1;
    string compressed = "";
    string repetitiveWord;
    cout << "Enter the repititive String: ";
    cin >> repetitiveWord;
    for (int i = 0; i < repetitiveWord.length() - 1; i++)
    {
        if (repetitiveWord[i] == repetitiveWord[i + 1])
        {
            count++;
        }

        else
        {
            compressed += repetitiveWord[i];
            compressed += to_string(count);
            count = 1; // for next repeating word...
        }
    }
    cout << "compressed String:  " << compressed << endl;
    return 0;
}