#include <iostream>
using namespace std;

int main()
{
	int _tabs, _salary;
	cin >> _tabs >> _salary;

	int _tax;
	for (int i = 0; i < _tabs; i++)
	{
		string tab;
		cin >> tab;

		if (tab == "Facebook")
		{
			_salary -= 150;
		}
		else if (tab == "Instagram")
		{
			_salary -= 100;
		}
		else if (tab == "Reddit")
		{
			_salary -= 50;
		}
	}

	if (_salary <= 0)
	{
		cout << "You have lost your salary." << endl;
	}
	else
	{
		cout << _salary << endl;
	}
}
