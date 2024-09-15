#include <iostream>

using namespace std;

int main()
{
	int begin, end;
	cin >> begin >> end;

	int sum = 0;
	for (int i = begin; i <= end; i++)
	{
		cout << i << ' ';
		sum += i;
	}

	cout << endl;
	cout << "Sum: " << sum << endl;
}
