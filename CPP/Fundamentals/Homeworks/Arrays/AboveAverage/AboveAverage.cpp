#include <iostream>

using namespace std;

int main()
{
	int array[100];
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		array[i] = num;
		sum += array[i];
	}
	int average = sum / n;
	for (int i = 0; i < n; i++)
	{
		if (array[i] >= average) 
		{
			cout << array[i] << " ";
		}
	}
}
