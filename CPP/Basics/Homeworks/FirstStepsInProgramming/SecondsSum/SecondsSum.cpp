#include <iostream>

using std::cin;
using std::cout;
using std::ios;
using std::endl;

int main()
{
	double _usd;

	cin >> _usd;

	double _bgn = _usd * 1.79549;

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << _bgn << endl;

	return 0;
}
