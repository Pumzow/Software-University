#include <iostream>

using namespace std;

int main()
{
	int _chickenMenus, _fishMenus, _vegeterianMenus;

	double _chickenMenuPrice = 10.35;
	double _fishMenuPrice = 12.40;
	double _vegeterianMenuPrice = 8.15;
	double _deliveryPrice = 2.50;

	cin >> _chickenMenus;
	cin >> _fishMenus;
	cin >> _vegeterianMenus;

	double _chickenOrderPrice = _chickenMenus * _chickenMenuPrice;
	double _fishOrderPrice = _fishMenus * _fishMenuPrice;
	double _vegeterianOrderPrice = _vegeterianMenus * _vegeterianMenuPrice;

	double _totalPrice = _chickenOrderPrice + _fishOrderPrice + _vegeterianOrderPrice;
	_totalPrice += _totalPrice * 0.20 + _deliveryPrice;

	cout << _totalPrice << endl;
}
