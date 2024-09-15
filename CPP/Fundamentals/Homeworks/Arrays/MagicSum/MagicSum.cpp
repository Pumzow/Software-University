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
	int magicSum;
	cin >> magicSum;

	for (int i = 0; i < n; i++)
	{
		for (int l = i; l < n; l++)
		{
			if (i == l) continue;
			if (array[i] + array[l] != magicSum) continue;
			cout << array[i]<< " " << array[l] << endl;
		}
	}
}
