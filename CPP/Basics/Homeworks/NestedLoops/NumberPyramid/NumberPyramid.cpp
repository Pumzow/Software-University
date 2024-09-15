#include <iostream>

using namespace std;

int main()
{
	int _n;
	cin >> _n;

	int _current = 0;
	bool _isBigger = false;
	for (int i = 1; i <= _n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			_current++;
			if (_current > _n)
			{
				_isBigger = true;
				break;
			}
			cout << _current << " ";
		}
		if (_isBigger) break;
		cout << endl;
	}
}
