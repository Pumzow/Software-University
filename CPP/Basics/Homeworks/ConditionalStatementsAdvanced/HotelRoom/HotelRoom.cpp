#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	string _month;
	int _nights;

	cin >> _month >> _nights;

	double _studioPrice;
	double _apartmentPrice;
	if (_month == "May" || _month == "October")
	{
		_studioPrice = _nights * 50;
		_apartmentPrice = _nights * 65;
		if (_nights > 14)
		{
			_studioPrice -= _studioPrice * .3;
		}
		else if (_nights > 7)
		{
			_studioPrice -= _studioPrice * .05;
		}	 
	}
	else if (_month == "June" || _month == "September")
	{
		_studioPrice = _nights * 75.2;
		_apartmentPrice = _nights * 68.7;
		if (_nights > 14)
		{
			_studioPrice -= _studioPrice * .2;
		} 
	}
	else if (_month == "July" || _month == "August")
	{
		_studioPrice = _nights * 76;
		_apartmentPrice = _nights * 77;
	}

	if (_nights > 14)
	{
		_apartmentPrice -= _apartmentPrice * .1;
	}

	cout << fixed << setprecision(2) << "Apartment: " << _apartmentPrice << " lv." << endl;
	cout << fixed << setprecision(2) << "Studio: " << _studioPrice << " lv." << endl;
}
