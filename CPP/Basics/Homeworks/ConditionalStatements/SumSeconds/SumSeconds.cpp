#include <iostream>

using namespace std;

int main()
{
	int _timeFirst, _timeSecond, _timeThird;
	cin >> _timeFirst >> _timeSecond >> _timeThird;

	int _totalTime = _timeFirst + _timeSecond + _timeThird;

	int _minutes = _totalTime / 60;
	int _seconds = _totalTime % 60;

	if (_seconds < 10)
	{
		cout << _minutes << ":0" << _seconds << endl;
	}
	else
	{
		cout << _minutes << ":" << _seconds << endl;
	}
}