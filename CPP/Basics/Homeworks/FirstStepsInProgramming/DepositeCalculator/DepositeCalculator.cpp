#include <iostream>

using namespace std;

int main()
{
	double _depositeSum;
	int _deadline;
	double _dividend;

	cin >> _depositeSum;
	cin >> _deadline;
	cin >> _dividend;

	_dividend *= 0.01;

	double _sum = _depositeSum + _deadline * ((_depositeSum * _dividend) / 12);

	cout << _sum << endl;

	return 0;
}