#include <iostream>

using namespace std;

int main()
{
	double num1, num2, num3;
	cin >> num1 >>num2>>num3;

	double result = num1 * num2 * num3;

	if (result < 0)
	{
		cout << '-' << endl;
	}
	else
	{
		cout << '+' << endl;
	}
}
