#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int input = n;

    int factorialSum = 0;

    while (n > 0)
    {
        int number = n % 10;

        int factorial = 1;

        for (int i = 1; i <= number; i++)
        {
            factorial *= i;
        }

        factorialSum += factorial;

        n /= 10;
    }

    if (factorialSum == input)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}
