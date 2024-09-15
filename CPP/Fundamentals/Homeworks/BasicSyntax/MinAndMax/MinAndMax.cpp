#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int min = 100000;
	int max = -100000;
	for (int i = 0; i < n; i++)
	{
		int current;
		cin >> current;
		if (current < min)
		{
			min = current;
		}
		if (current > max)
		{
			max = current;
		}
	}

	cout << min << ' ' << max << endl;
}
