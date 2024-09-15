#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string s, string sep)
{
	vector<string> results;
	auto pos = s.find(sep);
	while (pos != -1)
	{
		string token = s.substr(0, pos);
		results.push_back(token);
		s = s.substr(pos + sep.size());
		pos = s.find(sep);
	}
	results.push_back(s);
	return results;
}

int main()
{
	string input;
	getline(cin >> ws, input);
	vector<string> info = split(input, " ");

	vector<int> numbers;

	for (int i = 0; i < info.size(); i++)
	{
		numbers.push_back(stoi(info.at(i)));
	}

	bool even = info.size() % 2 == 1;
	int half = info.size() * .5;

	for (int i = 0; i < half; i++)
	{
		int number = numbers.at(i);
		int number1 = numbers.at(numbers.size() - 1 - i);
		cout << number + number1 << " ";
	}

	if (even)
	{
		cout << numbers.at(half);
	}
}
