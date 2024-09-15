#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> numbers;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		numbers.push_back(number);
		sum += number;
	}

	int average = sum / n;

	int evenSum = 0;
	int oddSum = 0;
	for (int i = 0; i < n; i++)
	{
		int number = numbers.at(i);
		if (number > average) continue;
		if (i % 2 == 0)
		{
			evenSum += number;
		}
		else
		{
			oddSum += number;
		}
	}

	cout << evenSum * oddSum << endl;
}
