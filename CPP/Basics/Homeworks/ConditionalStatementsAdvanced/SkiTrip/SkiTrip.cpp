#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int _days;
	string _type, _grade;

	cin >> _days;
	cin.ignore();
	getline(std::cin, _type);
	cin >> _grade;
	int _nights = _days - 1;

	double _price;
	if (_type == "room for one person")
	{
		_price = _nights * 18;
	}
	else if (_type == "apartment")
	{
		_price = _nights * 25;

		if (_days < 10)
		{
			_price -= _price * .3;
		}
		else if (_days < 15)
		{
			_price -= _price * .35;
		}
		else
		{
			_price -= _price * .5;
		}
	}
	else if (_type == "president apartment")
	{
		_price = _nights * 35;

		if (_days < 10)
		{
			_price -= _price * .1;
		}
		else if (_days < 15)
		{
			_price -= _price * .15;
		}
		else
		{
			_price -= _price * .20;
		}
	}

	if (_grade == "positive")
	{
		_price += _price * .25;
	}
	else
	{
		_price -= _price * .1;
	}

	cout << fixed << setprecision(2) << _price;
}
