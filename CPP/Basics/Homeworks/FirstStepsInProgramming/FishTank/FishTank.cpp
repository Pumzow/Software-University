#include <iostream>

using namespace std;

int main()
{
	int _length, _width, _heigth;
	double _percent;

	cin >> _length;
	cin >> _width;
	cin >> _heigth;
	cin >> _percent;

	int _volume = _length * _width * _heigth;
	double _requiredLiters = _volume * .001 * (1 - _percent * .01);

	cout << _requiredLiters;
}