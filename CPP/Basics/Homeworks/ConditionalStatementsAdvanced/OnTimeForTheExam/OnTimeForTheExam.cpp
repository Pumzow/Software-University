#include <iostream>

using namespace std;

int main()
{
	int _examHour, _examMinute, _arrivalHour, _arrivalMinute;

	cin >> _examHour >> _examMinute >> _arrivalHour >> _arrivalMinute;

	int _examTotalTime = _examHour * 60 + _examMinute;
	int _arrivalTotalTime = _arrivalHour * 60 + _arrivalMinute;

	if (_examTotalTime < _arrivalTotalTime)
	{
		cout << "Late" << endl;
		int _diff = _arrivalTotalTime - _examTotalTime;

		if (_diff < 60)
		{
			cout << _diff << " minutes after the start" << endl;
		}
		else
		{
			int _hours = _diff / 60;
			int _minutes = _diff %  60;
			if (_minutes < 10)
			{
				cout << _hours << ":0" << _minutes << " hours after the start" << endl;
			}
			else
			{
				cout << _hours << ":" << _minutes << " hours after the start" << endl;
			}
		}
	}
	else
	{

		int _diff = _examTotalTime - _arrivalTotalTime;

		if (_diff <= 30)
		{
			cout << "On time" << endl;
		}
		else
		{
			cout << "Early" << endl;
		}
		if (_diff < 60)
		{
			cout << _diff << " minutes before the start" << endl;
		}
		else
		{
			int _hours = _diff / 60;
			int _minutes = _diff %  60;
			if (_minutes < 10)
			{
				cout << _hours << ":0" << _minutes << " hours before the start" << endl;
			}
			else
			{
				cout << _hours << ":" << _minutes << " hours before the start" << endl;
			}
		}
	}
}
