#include <iostream>
int main()
{
	using namespace std;

	int length;
	cin >> length;

	int frequency[10] = { 0 };
	for (int i = 0; i < length; ++i)
	{
		int n;
		cin >> n;
		frequency[n]++;
	}

	int max_frequency = 0;
	for (int i = 0; i < 10; ++i)
		if (max_frequency < frequency[i])
			max_frequency = frequency[i];

	for (int i = 0; i < 10; ++i)
		if (frequency[i] == max_frequency)
			cout << i << ' ';

	return 0;
}