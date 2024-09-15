#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int vowels = 0;
	int nonVowels = 0;
	for (int i = 0; i < n; i++)
	{
		char input;
		cin >> input;

		if (!isalpha(input)) continue;
		if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u' || input == 'y' || input == 'A' || input == 'E' || input == 'I' || input == 'O' || input == 'U' || input == 'Y')
		{
			vowels++;
		}
		else
		{
			nonVowels++;
		}
	}

	cout << vowels << " " << nonVowels <<endl;
}
