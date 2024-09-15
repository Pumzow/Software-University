#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int days;
	string type, grade;

	cin >> days;
	cin.ignore();
	getline(cin,type);
	cin >> grade;

	days--;
	double price = 0;
	if (type == "room for one person")
	{
		price = days * 18;
	}
	else if (type == "apartment")
	{
		price = days * 25;
		if (days < 10)
		{
			price -= price * .3;
		}
		else if (days >= 10 && days <= 15)
		{
			price -= price * .35;
		}
		else if (days > 15)
		{
			price -= price * .5;
		}
	}
	else if (type == "president apartment")
	{
		price = days * 35;
		if (days < 10)
		{
			price -= price * .1;
		}
		else if (days >= 10 && days <= 15)
		{
			price -= price * .15;
		}
		else if (days > 15)
		{
			price -= price * .2;
		}
	}
		 

	if (grade == "positive")
	{
		price += price * .25;
	}
	else if (grade == "negative")
	{
		price -= price * .1;
	}

	cout << fixed << setprecision(2) << price << endl;
}