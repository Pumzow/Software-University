#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	string output;
	for (int i = 0; i < input.size(); i++)
	{
		if (output.size() == 0 || output[output.size() - 1] != input[i])
		{
			output += input[i];
		}
	}

	cout << output;
}
