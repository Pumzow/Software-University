#include <iostream>

using namespace std;

int main()
{
	double _excursionPrice;
	cin >> _excursionPrice;

	int _puzzlesCount, _dollsCount, _bearsCount, _minionsCount, _trucksCount;
	cin >> _puzzlesCount >> _dollsCount >> _bearsCount >> _minionsCount >> _trucksCount;

	int _totalCount = _puzzlesCount + _dollsCount + _bearsCount + _minionsCount + _trucksCount;

	double _orderPrice = _puzzlesCount * 2.6 + _dollsCount * 3 + _bearsCount * 4.1 + _minionsCount * 8.2 + _trucksCount * 2;

	if (_totalCount >= 50)
	{
		_orderPrice = _orderPrice - (_orderPrice * .25);
	}

	_orderPrice -= _orderPrice * .1;

	if (_orderPrice < _excursionPrice)
	{
		double _result = _excursionPrice - _orderPrice;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Not enough money! " << _result << " lv needed." << endl;
	}
	else
	{
		double _result = _orderPrice - _excursionPrice;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Yes! " << _result << " lv left." << endl;
	}
}
