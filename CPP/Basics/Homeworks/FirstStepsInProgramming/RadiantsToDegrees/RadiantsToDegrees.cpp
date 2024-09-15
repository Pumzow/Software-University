#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double _radiands;

	cin >> _radiands;

	double _degrees = _radiands * 180 / 3.14;

	cout << round(_degrees) << endl;
}
