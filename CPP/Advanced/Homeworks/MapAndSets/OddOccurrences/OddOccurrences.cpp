#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include <utility>

using namespace std;

void make_lower(string& word)
{
	for (char& ch : word)
		ch = tolower(ch);
}

int main()
{
	string line;
	getline(cin, line);

	istringstream iss(line);
	string word;
	using word_count = pair<string, int>;
	vector<word_count> words;
	while (getline(iss, word, ' '))
	{
		make_lower(word);
		int i;
		for (i = 0; i < words.size(); i++)
			if (word == words[i].first)
			{
				words[i].second++;
				break;
			}
		if (words.size() == i)
			words.push_back(make_pair(word, 1));
	}

	string separator = "";
	for (const auto& p : words)
		if (p.second % 2 == 1)
		{
			cout << separator << p.first;
			separator = ", ";
		}
	cout << endl;
}