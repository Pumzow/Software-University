#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int _budget, _fishersCount;
	string _season;

	cin >> _budget >> _season >> _fishersCount;

	double _price;

	if (_season == "Spring")
	{
		_price = 3000;
	}
	else if (_season == "Summer" || _season == "Autumn")
	{
		_price = 4200;
	}
	else if (_season == "Winter")
	{
		_price = 2600;
	}

	if (_fishersCount <= 6)
	{
		_price -= _price * .1;
	}
	else if (_fishersCount <= 11)
	{
		_price -= _price * .15;
	}
	else
	{
		_price -= _price * .25;
	}

	if (_season != "Autumn" && _fishersCount % 2 == 0)
	{
		_price -= _price * .05;
	}

	if (_budget >= _price)
	{
		cout << fixed << setprecision(2) << "Yes! You have " << _budget - _price << " leva left." << endl;
	}
	else
	{
		cout << fixed << setprecision(2) << "Not enough money! You need " << _price - _budget << " leva." << endl;
	}
}
