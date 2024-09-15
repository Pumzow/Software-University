#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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

class Sentence
{
	vector<string> words;
public:
	Sentence(vector<string> w)
	{
		words = w;
	}

	vector<string> getShiftedSentence(int n)
	{
		int shiftAmount = n % words.size();

		vector<string> temp(words.size());

		for (int i = 0; i < words.size(); ++i)
		{
			int newPos = (i + shiftAmount + words.size()) % words.size();
			temp[newPos] = words[i];
		}

		for (int i = 0; i < words.size(); ++i)
		{
			words[i] = temp[i];
		}

		return words;
	}
};

int main()
{
	string input;
	int r;
	getline(cin >> ws, input);
	vector<string> info = split(input, " ");
	cin >> r;
	Sentence sentence(info);
	vector<string> rotated = sentence.getShiftedSentence(r);
	for (size_t i = 0; i < rotated.size(); i++)
	{
		cout << rotated.at(i) << endl;
	}
}
