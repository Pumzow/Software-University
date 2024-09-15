#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int array1[100];
	int array2[100];
	int i1 = 0;
	int i2 = 0;
	for (int i = 0; i < n * 2; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		if (i % 2 == 0)
		{
			array1[i1++] = num1;
			array2[i2++] = num2;
		}
		else
		{
			array1[i1++] = num2;
			array2[i2++] = num1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << array2[i] << " ";
	}
}
