#include <iostream>

using namespace std;

int main()
{
	int array[100];

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		array[i] = e;
	}

	int biggestNumber = 0;
	int longestSequence = 0;

	for (int i = 0; i < n; i++)
	{
		int sequence = 0;
		for (int l = 0; l < n; l++)
		{
			if (i == l) continue;

			if (array[i] == array[l])
			{
				sequence++;
			}
		}

		if (sequence >= longestSequence)
		{
			longestSequence = sequence;
			biggestNumber = array[i];
		}
	}

	for (int i = 0; i < longestSequence + 1; i++)
	{
		cout << biggestNumber << " ";
	}
}
