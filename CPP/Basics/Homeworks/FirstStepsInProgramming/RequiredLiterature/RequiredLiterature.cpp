#include <iostream>

using namespace std;

int main()
{
	int _pagesCount, _pages, _days;

	cin >> _pagesCount;
	cin >> _pages;
	cin >> _days;

	int _hours = _pagesCount / _pages / _days;

	cout << _hours << endl;

	return 0;
}