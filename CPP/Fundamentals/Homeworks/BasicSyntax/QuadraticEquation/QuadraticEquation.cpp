#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double discr = b * b - 4 * a * c;
	if (discr < 0)
	{
		cout << "no roots" << endl;
		return 0;
	}
	discr = sqrt(discr);

	double r1 = (-b + discr) / (2 * a);
	double r2 = (-b - discr) / (2 * a);

	if (discr == 0)
	{
		cout << r1 << endl;
	}
	else
	{
		cout << r1 << ' ' << r2 << endl;
	}
}
