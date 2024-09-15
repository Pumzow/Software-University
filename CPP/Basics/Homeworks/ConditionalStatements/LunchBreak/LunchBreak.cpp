#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	string _name = "Teen Wolf";
	int _episodeLength = 48, _breakLength = 60;

	getline(cin, _name);
	cin >> _episodeLength;
	cin >> _breakLength;

	double _timeForLunch = _breakLength * .125;
	double _timeForBreak = _breakLength * .25;

	double _timeLeft = _breakLength - _timeForLunch - _timeForBreak;

	if (_timeLeft < _episodeLength)
	{
		cout << "You don't have enough time to watch " << _name << ", you need " << ceil(_episodeLength - _timeLeft) << " more minutes." << endl;
	}
	else
	{
		cout << "You have enough time to watch " << _name << " and left with " << ceil(_timeLeft - _episodeLength) << " minutes free time." << endl;
	}
}
