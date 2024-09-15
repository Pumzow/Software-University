#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	char previous = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (isalpha(input[i]) && !isalpha(previous))
		{
			input[i] = toupper(input[i]);
		}
		previous = input[i];
	}
	cout << input;
}
