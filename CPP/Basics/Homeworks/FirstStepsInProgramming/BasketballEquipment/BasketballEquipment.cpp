#include <iostream>

using namespace std;

int main()
{
	int _yearlyTax;

	cin >> _yearlyTax;

	double _shoes = _yearlyTax - _yearlyTax * .4;
	double _outfit = _shoes - _shoes * .2;
	double _ball = _outfit * .25;
	double _accessoaries = _ball * .2;

	double _expenses = _yearlyTax + _shoes + _outfit + _ball + _accessoaries;

	cout << _expenses << endl;
}