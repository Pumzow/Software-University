#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double _budget;
	string _season;

	cin >> _budget >> _season;

	string _destination;
	string _type;
	double _price;
	if (_budget <= 100)
	{
		_destination = "Bulgaria";
		if (_season == "summer")
		{
			_type = "Camp";
			_price = _budget * .3;
		}
		else if (_season == "winter")
		{
			_type = "Hotel";
			_price = _budget * .7;
		}
	}
	else if (_budget <= 1000)
	{
		_destination = "Balkans";
		if (_season == "summer")
		{
			_type = "Camp";
			_price = _budget * .4;
		}
		else if (_season == "winter")
		{
			_type = "Hotel";
			_price = _budget * .8;
		}
	}
	else
	{
		_type = "Hotel";
		_destination = "Europe";
		_price = _budget * .9;
	}

	cout << "Somewhere in " << _destination << endl;
	cout << fixed << setprecision(2) << _type << " - " << _price << endl;
}
