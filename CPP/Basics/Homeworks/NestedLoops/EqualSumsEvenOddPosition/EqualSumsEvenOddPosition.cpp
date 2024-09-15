#include <iostream>
#include <string>

using namespace std;

int main()
{
	int _n, _m;
	cin >> _n >>_m;

    for (int i = _n; i <= _m; i++)
    {
        string num = to_string(i);

        int evenSum = 0;
        int oddSum = 0;

        for (int j = 0; j < num.length(); j++)
        {
            char magic = num[j];
            int digit = (int)magic;

            if (j % 2 == 0)
            {
                evenSum += digit;
            }
            else
            {
                oddSum += digit;
            }
        }
        if (evenSum == oddSum)
        {
            cout << i << " ";
        }
    }
}
