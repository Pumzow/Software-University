#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		input[i] += 3;
	}

	cout << input;
}
