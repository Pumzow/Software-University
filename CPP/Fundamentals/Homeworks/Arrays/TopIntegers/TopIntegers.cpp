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
		bool result = true;
		for (int l = i; l < n; l++)
		{
			if (l == i) continue;
			if (array[i] <= array[l])
			{
				result = false;
				break;
			}
		}
		if (result)
		{
			cout << array[i] << " ";
		}
	}
}
