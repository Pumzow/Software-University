#include <iostream>
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

void print(vector<string>& wagons)
{
	if (wagons.size() <= 0) return;
	for (int i = 0; i < wagons.size(); i++)
	{
		cout << "|" << wagons[i];
	}
	cout << "|" << endl;
}

int main()
{
	vector<string> wagons;
	while (true)
	{
		string input;
		getline(cin >> ws, input);
		if (input == "end") break;

		wagons.push_back(input == "empty" ? " " : input);
	}
	while (true)
	{
		string input;
		getline(cin >> ws, input);

		vector<string> command = split(input, " ");
		if (command[0] == "P")
		{
			print(wagons);
		}
		else if (command[0] == "M")
		{
			string oldPositionWagon = wagons[stoi(command[1]) - 1];
			wagons.erase(wagons.begin() + stoi(command[1]) - 1);
			if (stoi(command[2]) - 1 >= wagons.size())
			{
				wagons.push_back(oldPositionWagon);
			}
			else
			{
				wagons.insert(wagons.begin() + stoi(command[2]) - 1, oldPositionWagon);
			}

			print(wagons);
		}
		else if (command[0] == "L")
		{
			wagons.erase(wagons.begin() + stoi(command[1]) - 1);
			print(wagons);
		}
		else if (command[0] == "E")
		{
			break;
		}
	}
}
