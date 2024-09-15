#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double _recordInSeconds , _distanceInMeters, _timeInSeconds;
	

	cin >> _recordInSeconds >> _distanceInMeters >> _timeInSeconds;
	double _waterFallbackSpeed = floor(_distanceInMeters / 15) * 12.5;

	double _finalPersonalRecord = _distanceInMeters * _timeInSeconds + _waterFallbackSpeed;

	if (_recordInSeconds > _finalPersonalRecord)
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Yes, he succeeded! The new world record is " <<  _finalPersonalRecord << " seconds." << endl;
	}
	else
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "No, he failed! He was " << _finalPersonalRecord - _recordInSeconds << " seconds slower." << endl;
	}
}
