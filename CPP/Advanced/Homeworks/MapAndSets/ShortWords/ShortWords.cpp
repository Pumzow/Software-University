#include <iostream>
#include <string>
#include <vector>
#include <map>

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

void make_lower(string& word)
{
	for (char& ch : word)
		ch = tolower(ch);
}

int main()
{
	string input;
	getline(cin >> ws, input);
	vector<string> words = split(input, " ");

	map<string, int> wordsMap;

	for (int i = 0; i < words.size(); i++)
	{
		if (words.at(i).size() >= 5) continue;

		string word = words.at(i);
		make_lower(word);
		wordsMap[word]++;
	}

	string separator = "";
	for (auto const& keyValue : wordsMap)
	{
		cout << separator << keyValue.first;
		separator = ", ";
	}
}