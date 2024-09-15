#include <iostream>

using namespace std;


void Sum(int a, int b)
{
	cout << a + b << endl;
}

void Suntract(int a, int b)
{
	cout << a - b << endl;
}

void Multiply(int a, int b)
{
	cout << a * b << endl;
}

void Divide(int a, int b)
{
	cout << a / b << endl;
}

int main()
{
	int a, b;
	cin >> a >> b;
	string operation;
	cin >> operation;

	if (operation == "+")
	{
		Sum(a, b);
	}
	else if (operation == "-")
	{
		Suntract(a, b);
	}
	else if (operation == "*")
	{
		Multiply(a, b);
	}
	else if (operation == "/")
	{
		Divide(a, b);
	}
}