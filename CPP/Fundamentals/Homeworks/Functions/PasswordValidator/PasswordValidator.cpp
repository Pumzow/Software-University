#include <iostream>

using namespace std;

bool ValidateLenght(string password)
{
	if (password.size() < 6 || password.size() > 10)
	{
		cout << "Password must be between 6 and 10 characters" << endl;
		return false;
	}
	return true;
}

bool ValidateSymbols(string password)
{
	for (int i = 0; i < password.length(); i++)
	{
		if ((password[i] >= 48 && password[i] <= 57) ||
			(password[i] >= 65 && password[i] <= 90) ||
			(password[i] >= 97 && password[i] <= 122))
		{
			continue;
		}
		else
		{
			cout << "Password must consist only of letters and digits" << endl;
			return false;
		}
	}
	return true;
}

bool ValidateDigits(string password)
{
	int digits = 0;
	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] == '0' || password[i] == '1' || password[i] == '2' || password[i] == '3' || password[i] == '4' || password[i] == '5' || password[i] == '6' || password[i] == '7' || password[i] == '8' || password[i] == '9')
		{
			digits++;
		}
	}
	if (digits < 2)
	{
		cout << "Password must have at least 2 digits" << endl;
		return false;
	}
	return true;
}

int main()
{
	string password;
	cin >> password;
	bool valid = true;
	if (!ValidateLenght(password))
	{
		valid = false;
	}
	if (!ValidateSymbols(password))
	{
		valid = false;
	}
	if (!ValidateDigits(password))
	{
		valid = false;
	}

	if (valid)
	{
		cout << "Password is valid" << endl;
	}
}
