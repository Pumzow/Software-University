#include <iostream>
#include <string>

using namespace std;

string digits[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string tens[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

void ZeroToHundred(int input)
{
	if (input < 10) cout << digits[input];
	else if (input < 20) cout << teens[input - 10];
	else if (input < 100)
	{
		int t = input / 10;
		int e = input % 10;
		cout << tens[t - 2];
		if (e > 0) cout << " " << digits[e];
	}
}
void Hundreds(int input)
{
	int hundreds = input / 100;
	int low = input % 100;
	if (hundreds > 0) cout << digits[hundreds] << " hundred ";
	if (low > 0) ZeroToHundred(low);
}

int main()
{
	int input;
	cin >> input;

	if (input < 100) ZeroToHundred(input);
	else if (input < 1000) Hundreds(input);
	else if (input < 10000)
	{
		int thousands = input / 1000;
		cout << digits[thousands] << " thousand ";
		Hundreds(input % 1000);
	}
}
