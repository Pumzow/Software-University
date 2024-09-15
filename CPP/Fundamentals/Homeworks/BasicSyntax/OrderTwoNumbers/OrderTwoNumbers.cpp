#include <iostream>
#include <string>

using namespace std;

int main()
{
	int number1, number2;
	cin >> number1 >> number2;

	if (number1 < number2)
	{
		cout << number1 << ' ' << number2 << endl;
	}
	else
	{
		cout << number2 << ' ' << number1 << endl;
	}
}