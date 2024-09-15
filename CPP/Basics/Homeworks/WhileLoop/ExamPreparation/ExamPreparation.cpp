#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int _maxBadGrades;
	cin >> _maxBadGrades;

	string _lastProblem;
	double _gradesSum = 0;
	int _problems = 0;
	int _badGrades = 0;

	while (true)
	{
		string _taskName;
		cin.ignore();
		getline(cin, _taskName);

		int _grade;
		cin >> _grade;

		if (_grade <= 4)
		{
			_badGrades++;
			if (_badGrades == _maxBadGrades)
			{
				cout << "You need a break, " << _badGrades << " poor grades." << endl;
				break;
			}
		}

		if (_taskName == "Enough")
		{
			cout << "Average score: " << fixed <<  setprecision(2) <<_gradesSum/ _problems << endl;
			cout << "Number of problems: " << _problems << endl;
			cout << "Last problem: " << _lastProblem << endl;
			break;
		}

		_gradesSum += _grade;
		_problems++;
		_lastProblem = _taskName;
	}
}
