#include <iostream>

using namespace std;

int main()
{
	double _budget = 900;
	int _gpuCount = 2, _cpuCount = 1, _ramCount = 3;

	cin >> _budget >> _gpuCount >> _cpuCount >> _ramCount;

	double _gpuPrice = _gpuCount * 250;
	double _cpuPrice = _gpuPrice * .35;
	double _ramPrice = _gpuPrice * .1;

	double _totalPrice = _gpuPrice + _cpuPrice * _cpuCount + _ramPrice * _ramCount;

	if (_gpuCount > _cpuCount)
	{
		_totalPrice -= _totalPrice * .15;
	}

	if (_totalPrice <= _budget)
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "You have " << _budget - _totalPrice << " leva left!" << endl;
	}
	else
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Not enough money! You need " << _totalPrice - _budget << " leva more!" << endl;
	}
}
