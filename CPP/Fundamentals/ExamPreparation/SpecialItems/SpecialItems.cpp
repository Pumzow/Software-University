#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	char last = 'a';
	string result = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
		{
			last = input[i];
			result += input[i];
			continue;
		}

		if (last != input[i])
		{
			result += input[i];
			last = input[i];
		}
	}

	cout << result << endl;
}
