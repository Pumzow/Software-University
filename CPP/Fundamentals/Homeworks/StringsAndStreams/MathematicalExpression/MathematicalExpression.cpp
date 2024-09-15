#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	int open = 0;
	int close = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			open++;
		}
		if (input[i] == ')')
		{
			close++;
		}
	}

	string result = open == close ? "correct" : "incorrect";
	cout << result;
}
