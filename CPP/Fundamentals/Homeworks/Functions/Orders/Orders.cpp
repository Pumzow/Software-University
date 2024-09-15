#include <iostream>
#include <iomanip>

using namespace std;

double GetProductPrice(string product, int quantity)
{
	double price = 0;
	if (product == "water")
	{
		price = 1 * quantity;
	}
	else if (product == "coffee")
	{
		price = 1.5 * quantity;
	}
	else if (product == "coke")
	{
		price = 1.4 * quantity;
	}
	else if (product == "snacks")
	{
		price = 2 * quantity;
	}
	return price;
}

int main()
{
	string product;
	int quantity;

	cin >> product;
	cin >> quantity;

	cout << fixed << setprecision(2) << GetProductPrice(product, quantity);
}
