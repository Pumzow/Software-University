#include <iostream>
#include <string>;

using namespace std;

int GetVolewsCount(string text)
{

	int result = 0;
	for (int i = 0; i < text.size(); i++)
	{
		char c = std::tolower(text[i]);
		if (c == 'a' || c == 'e' || c == 'y' || c == 'o' || c == 'u' || c == 'i')
		{
			result++;
		}
	}

	return result;
}

int main()
{
	string input;
	cin >> input;

    std::cout << GetVolewsCount(input);
}
