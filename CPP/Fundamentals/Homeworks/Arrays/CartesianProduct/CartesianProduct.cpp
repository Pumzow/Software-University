#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int array[100];

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		array[i] = num;
	}

	for (int i = 0; i < n; i++)
	{
		for (int l = 0; l < n; l++)
		{
			cout << array[i] * array[l] << " ";
		}
	}
}