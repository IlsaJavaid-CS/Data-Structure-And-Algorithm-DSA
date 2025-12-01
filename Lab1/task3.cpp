#include <iostream>
using namespace std;

int IterativeSum(int num)
{
    int sum = 0;
    while (num != '\0') // go to the end of the number....
    {
        int remainder = num % 10;
        sum += remainder;
        num = num / 10;
    }
    return sum;
}

int recursiveSum(int num)
{
    if (num == 0)
        return 0;
    return (num % 10) + recursiveSum(num / 10);
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Your iterative Sum is: " << IterativeSum(number);
    cout << "Your recursive Sum is:" << recursiveSum(number);
    return 0;
}