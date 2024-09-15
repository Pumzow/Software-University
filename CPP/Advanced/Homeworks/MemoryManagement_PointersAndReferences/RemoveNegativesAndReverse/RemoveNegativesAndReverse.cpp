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
	vector<int> result;
	for (int i = 0; i < info.size(); i++)
	{
		int number = stoi(info.at(i));
		if (number < 0) continue;
		result.push_back(number);
	}

	if (result.empty())
	{
		cout << "empty";
	}
	else
	{
		for (int i = result.size() - 1; i >= 0; i--)
		{
			cout << result.at(i) << " ";
		}
	}
}
