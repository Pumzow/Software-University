#include <iostream>
#include <string>
#include <locale>

using namespace std;

string to_lower(string s)
{
	for (char& c : s)
	{
		c = tolower(c);
	}
	return s;
}

string to_upper(string s)
{
	for (char& c : s)
	{
		c = toupper(c);
	}
	return s;
}

int main()
{
	string input;
	getline(cin, input);

	cout << to_lower(input) << endl;
	cout << to_upper(input) << endl;
}