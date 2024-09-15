#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input1, input2;
	cin >> input1 >> input2;

	int size;
	size = max(input1.size(), input2.size());

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		int a = 1;
		int b = 1;
		if (input1.size() > i)
		{
			a = input1[i];
		}
		if (input2.size() > i)
		{
			b = input2[i];
		}
		sum += a * b;
	}

	cout << sum;
}
