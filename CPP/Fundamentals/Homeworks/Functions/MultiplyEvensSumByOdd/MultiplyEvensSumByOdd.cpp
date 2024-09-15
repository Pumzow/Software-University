#include <iostream>
#include <string>

using namespace std;

int GetEvenSum(string n)
{
	int result = 0;
	for (int i = 0; i < n.length(); i++)
	{
		int number = (n[i] - '0');
		if (number % 2 == 0)
		{
			result += number;
		}
	}
	return result;
}

int GetOddSum(string n)
{
	int result = 0;
	for (int i = 0; i < n.length(); i++)
	{
		int number = (n[i] - '0');
		if (number % 2 == 1)
		{
			result += number;
		}
	}
	return result;
}


int main()
{
	string n;
	cin >> n;

	int evenSum = GetEvenSum(n);
	int oddSum = GetOddSum(n);

	cout << evenSum * oddSum << endl;
}
