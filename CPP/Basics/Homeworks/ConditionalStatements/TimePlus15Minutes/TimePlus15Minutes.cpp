#include <iostream>

using namespace std;

int main()
{
	int _startHours, _startMinutes;
	cin >> _startHours >> _startMinutes;

	int _timeInMinutes = _startHours * 60 + _startMinutes;
	int _timePlus15 = _timeInMinutes + 15;

	int _finalHours = _timePlus15 / 60;
	int _finalMinutes = _timePlus15 % 60;

	if (_finalHours >= 24)
	{
		_finalHours -= 24;
	}


	if (_finalMinutes < 10)
	{
		cout << _finalHours << ":0" << _finalMinutes << endl;
	}
	else
	{
		cout << _finalHours << ":" << _finalMinutes << endl;
	}
}
