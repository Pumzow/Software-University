#include <iostream>

using namespace std;

int main()
{
	int _requiredNylon, _requiredPainting, _requiredThinner, _hours;

	cin >> _requiredNylon;
	cin >> _requiredPainting;
	cin >> _requiredThinner;
	cin >> _hours;
	
	double _nylonPrice = (_requiredNylon + 2) * 1.50;
	double _paintingPrice = (_requiredPainting + (_requiredPainting * 0.1)) * 14.50;
	double _thinnerPrice = _requiredThinner * 5.00;
	double _bagPrice = 0.40;

	double _totalPrice = _nylonPrice + _paintingPrice + _thinnerPrice + _bagPrice;
	_totalPrice += (_totalPrice * 0.3) * _hours;

	cout << _totalPrice << endl;
}
