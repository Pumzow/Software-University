#include <iostream>
#include <iomanip>

using namespace std;

double CalculateFactorial(int n)
{
	double result = 1;
	for (int i = 2; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout<< fixed << setprecision(2) << CalculateFactorial(a) / CalculateFactorial(b) << endl;
}
