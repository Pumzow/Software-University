#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int _firstNumber, _secondNumber;
	string _operation;

	cin >> _firstNumber >> _secondNumber >> _operation;

	if (_operation == "+")
	{
		int _result = _firstNumber + _secondNumber;
		string _type;
		if (_result % 2 == 0)
		{
			_type = "even";
		}
		else
		{
			_type = "odd";
		}
		cout << _firstNumber << " " << _operation << " " << _secondNumber << " = " << _result << " - " << _type << endl;
	}
	else if (_operation == "-")
	{
		int _result = _firstNumber - _secondNumber;
		string _type;
		if (_result % 2 == 0)
		{
			_type = "even";
		}
		else
		{
			_type = "odd";
		}
		cout << _firstNumber << " " << _operation << " " << _secondNumber << " = " << _result << " - " << _type << endl;
	}
	else if (_operation == "*")
	{
		int _result = _firstNumber * _secondNumber;
		string _type;
		if (_result % 2 == 0)
		{
			_type = "even";
		}
		else
		{
			_type = "odd";
		}
		cout << _firstNumber << " " << _operation << " " << _secondNumber << " = " << _result << " - " << _type << endl;
	}
	else if (_operation == "/")
	{
		if (_secondNumber == 0)
		{
			cout << "Cannot divide " << _firstNumber << " by zero";
			return 0;
		}

		double _result = (double)_firstNumber / (double)_secondNumber;
		cout << fixed << setprecision(2) << _firstNumber << " " << _operation << " " << _secondNumber << " = " << _result  << endl;
	}
	else if (_operation == "%")
	{
		if (_secondNumber == 0)
		{
			cout << "Cannot divide " << _firstNumber << " by zero";
			return 0;
		}

		int _result = _firstNumber % _secondNumber;
		cout << _firstNumber << " " << _operation << " " << _secondNumber << " = " << _result  << endl;
	}
}
