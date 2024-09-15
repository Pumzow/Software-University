#include <iostream>

using namespace std;

int main()
{
	int _points;
	double _bonus = 0;

	cin >> _points;

	if (_points <= 100)
	{
		_bonus += 5;
	}
	else if (_points > 1000)
	{
		_bonus += _points * .1;
	}
	else if (_points > 100)
	{
		_bonus += _points * .2;
	}

	if (_points % 2 == 0)
	{
		_bonus++;
	}
	else if (_points % 10 == 5)
	{
		_bonus += 2;
	}

	cout << _bonus << endl;
	cout << _bonus + _points << endl;
}
