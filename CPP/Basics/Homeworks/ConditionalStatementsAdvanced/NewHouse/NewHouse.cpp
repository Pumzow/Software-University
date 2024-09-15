#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string _type;
	int _count, _budget;

	cin >> _type >> _count >> _budget;

	double _price;
	if (_type == "Roses")
	{
		_price = 5 * _count;

		if (_count > 80)
		{
			_price -= _price * .1;
		}
	}
	else if (_type == "Dahlias")
	{
		_price = 3.8 * _count;

		if (_count > 90)
		{
			_price -= _price * .15;
		}
	}
	else if (_type == "Tulips")
	{
		_price = 2.8 * _count;

		if (_count > 80)
		{
			_price -= _price * .15;
		}
	}
	else if (_type == "Narcissus")
	{
		_price = 3 * _count;

		if (_count < 120)
		{
			_price += _price * .15;
		}
	}
	else if (_type == "Gladiolus")
	{
		_price = 2.5 * _count;

		if (_count < 80)
		{
			_price += _price * .2;
		}
	}

	if (_price <= _budget)
	{
		cout << fixed << setprecision(2) << "Hey, you have a great garden with " << _count << " " << _type << " and " << _budget - _price << " leva left." << endl;
	}
	else
	{
		cout << fixed << setprecision(2) << "Not enough money, you need " << _price - _budget << " leva more." << endl;
	}
}
