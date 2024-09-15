#include <iostream>

using namespace std;

int main()
{
	double _budget, _pricePerDress;
	int _statistsCount;

	cin >> _budget>> _statistsCount>> _pricePerDress;

	double _decorPrice = _budget * .1;

	if (_statistsCount > 150)
	{
		_pricePerDress -= _pricePerDress * .1;
	}

	double _dressPrice = _pricePerDress * _statistsCount;

	double _totalPrice = _dressPrice + _decorPrice;

	if (_budget >= _totalPrice)
	{

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Action!" << endl;
		cout << "Wingard starts filming with " << _budget - _totalPrice << " leva left." << endl;
	}
	else
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Not enough money!" << endl;
		cout << "Wingard needs " << _totalPrice - _budget << " leva more." << endl;
	}
}
