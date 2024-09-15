#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string _projections;
	int _rolls, _collums;

	cin >> _projections >> _rolls >> _collums;

	double _projectionPrice = 0;
	if (_projections == "Premiere")
	{
		_projectionPrice = 12;
	}
	else if (_projections == "Normal")
	{
		_projectionPrice = 7.5;
	}
	else if (_projections == "Discount")
	{
		_projectionPrice = 5;
	}

	double _price = _rolls * _collums * _projectionPrice;
	cout << fixed << setprecision(2) << _price << " leva" << endl;
}