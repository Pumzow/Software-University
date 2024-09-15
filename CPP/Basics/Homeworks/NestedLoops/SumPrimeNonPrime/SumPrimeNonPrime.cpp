#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;
	int primeSum = 0;
	int nonPrimeSum = 0;

	while (input != "stop")
	{
		int num = stoi(input);

		if (num < 0)
		{
			cout << "Number is negative." << endl;
			cin >> input;
			continue;
		}
		bool isPrime = true;

		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			primeSum += num;
		}
		else
		{
			nonPrimeSum += num;
		}

		cin >> input;
	}

	cout << "Sum of all prime numbers is: " << primeSum << endl;
	cout << "Sum of all non prime numbers is: " << nonPrimeSum;
}