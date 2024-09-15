#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string _actorName;
	double _actorPoints;
	int	_judges;

	getline(cin, _actorName);
	cin >> _actorPoints >> _judges;

	for (int i = 0; i < _judges; i++)
	{
		string _judgeName;
		double _judgePoints;

		cin.ignore();
		getline(cin, _judgeName);
		cin >> _judgePoints;

		_actorPoints += _judgePoints * _judgeName.length() / 2;

		if (_actorPoints > 1250.5)
		{
			cout << fixed<< setprecision(1) << "Congratulations, " << _actorName <<" got a nominee for leading role with " << _actorPoints << "!" << endl;
			break;
		}
	}

	if (_actorPoints < 1250.5)
	{
		cout << fixed << setprecision(1) << "Sorry, " << _actorName << " you need " << 1250.5 - _actorPoints << " more!" << endl;
	}
}
