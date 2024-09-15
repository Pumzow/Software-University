#include <iostream>
#include <string>

using namespace std;

int main()
{
	double _neededMoney;
	cin >> _neededMoney;
	double _money;
	cin >> _money;

	int _spentStreek = 0;
	int _daysPast = 0;
	while (true)
	{
		_daysPast++;
		string _type;
		cin >> _type;
		double _moneyInput;
		cin >> _moneyInput;

		if (_type == "spend")
		{
			_money -= _moneyInput;
			if (_money < 0) _money = 0;
			if (++_spentStreek >= 5)
			{
				cout << "You can't save the money." << endl;
				cout << _daysPast;
				break;
			}
		}
		else if (_type == "save")
		{
			_spentStreek = 0;
			_money += _moneyInput;
			if (_money >= _neededMoney)
			{
				cout << "You saved the money for " << _daysPast << " days." << endl;
				break;
			}
		}

	}
}
