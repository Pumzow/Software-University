#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	double totalLiters = 0;
	double totalDegrees = 0;

	for (int i = 0; i < n; i++)
	{
		double liters, degrees;
		cin >> liters >> degrees;

		totalLiters += liters;
		totalDegrees += liters * degrees;
	}

	double finalDegrees = totalDegrees / totalLiters;

	cout << fixed << setprecision(2) << "Liter: " << totalLiters << endl;
	cout << fixed << setprecision(2) << "Degrees: " << finalDegrees <<endl;

	if (finalDegrees < 38)
	{
		cout << "Not good, you should baking!" << endl;
	}
	else if (finalDegrees >= 38 && finalDegrees <= 42)
	{
		cout << "Super!" << endl;
	}
	else if (finalDegrees > 42)
	{
		cout << "Dilution with distilled water!" << endl;
	}
}