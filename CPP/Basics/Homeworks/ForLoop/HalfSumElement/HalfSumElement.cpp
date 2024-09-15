#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int _numbers;
	cin >> _numbers;

	int _maxNumber = INT_MIN;
	int _sum = 0;

	for (int i = 0; i < _numbers; i++)
	{
		int _num;
		cin >> _num;

		_sum += _num;

		if (_num > _maxNumber)
		{
			_maxNumber = _num;
		}
	}
	_sum -= _maxNumber;
	int _diff = _sum - _maxNumber;

	if (_diff != 0)
	{
		cout << "No" << endl;
		cout << "Diff = " << abs(_diff) << endl;
	}
	else
	{
		cout << "Yes" << endl;
		cout << "Sum = " << _sum << endl;
	}
}
