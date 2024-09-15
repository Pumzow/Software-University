#include <iostream>

using namespace std;

int main()
{
	int _pencils, _markers,  _cleaners, _discount;

	double _pencilsPrice = 5.80;
	double _markersPrice = 7.20;
	double _cleanerPrice = 1.20;

	cin >> _pencils;
	cin >> _markers;
	cin >> _cleaners;
	cin >> _discount;

	double _price = _pencils * _pencilsPrice + _markers * _markersPrice + _cleaners * _cleanerPrice;
	_price -= _price * (_discount * .01);

	cout << _price << endl;
}
