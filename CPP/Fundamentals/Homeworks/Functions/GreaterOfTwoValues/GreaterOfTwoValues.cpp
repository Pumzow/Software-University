#include <iostream>
#include <string>

using namespace std;

void PrintBiggerInt()
{
	int a, b;
	cin >> a;
	cin >> b;
	int result = a > b ? a : b;
	cout << result << endl;
}

void PrintBiggerString()
{
	string a, b;
	cin.ignore();
	getline(cin, a);
	getline(cin, b);
	string result = a >= b ? a : b;
	cout << result << endl;
}

void PrintBiggerChar()
{
	char a, b;
	cin >> a;
	cin >> b;
	char result = a > b ? a : b;
	cout << result << endl;
}

int main()
{
	string type;
	cin >> type;

	if (type == "int")
	{
		PrintBiggerInt();
	}
	else if(type == "string")
	{
		PrintBiggerString();
	}
	else if (type == "char")
	{
		PrintBiggerChar();
	}
}
