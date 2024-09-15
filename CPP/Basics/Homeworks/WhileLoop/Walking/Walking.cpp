#include <iostream>
#include <string>;

using namespace std;

int main()
{
	int _totalSteps = 0;
	while (true)
	{
		string _input;
		getline(cin, _input);

		if (_input == "Going home")
		{
			getline(cin, _input);
			_totalSteps += stoi(_input);

			if (_totalSteps >= 10000)
			{
				cout << "Goal reached! Good job!" << endl;
			}
			else
			{
				cout << 10000 - _totalSteps << " more steps to reach goal." << endl;
			}
			break;
		}
		
		_totalSteps += stoi(_input);

		if (_totalSteps >= 10000)
		{
			cout << "Goal reached! Good job!" << endl;
			break;
		}
	}
}
