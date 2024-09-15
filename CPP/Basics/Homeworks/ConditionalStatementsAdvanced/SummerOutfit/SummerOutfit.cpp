#include <iostream>

using namespace std;

int main()
{
	int _degrees;
	string _time;

	cin >> _degrees >> _time;

	if (10 <= _degrees && _degrees <= 18)
	{
		if (_time == "Morning")
		{
			cout << "It's " << _degrees << " degrees, get your Sweatshirt and Sneakers." << endl;
		}
		else if (_time == "Afternoon")
		{
			cout << "It's " << _degrees << " degrees, get your Shirt and Moccasins." << endl;
		}
		else
		{
			cout << "It's " << _degrees << " degrees, get your Shirt and Moccasins." << endl;
		}
	}
	else if (_degrees > 18 && _degrees <= 24)
	{
		if (_time == "Morning")
		{
			cout << "It's " << _degrees << " degrees, get your Shirt and Moccasins." << endl;
		}
		else if (_time == "Afternoon")
		{
			cout << "It's " << _degrees << " degrees, get your T-Shirt and Sandals." << endl;
		}
		else
		{
			cout << "It's " << _degrees << " degrees, get your Shirt and Moccasins." << endl;
		}
	}
	else
	{
		if (_time == "Morning")
		{
			cout << "It's " << _degrees << " degrees, get your T-Shirt and Sandals." << endl;
		}
		else if (_time == "Afternoon")
		{
			cout << "It's " << _degrees << " degrees, get your Swim Suit and Barefoot." << endl;
		}
		else
		{
			cout << "It's " << _degrees << " degrees, get your Shirt and Moccasins." << endl;
		}
	}
}
