#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

template <typename T>
bool contains(const std::vector<T>& vec, const T& element)
{
	bool contains = false;
	for (int j = 0; j < vec.size(); j++)
	{
		if (vec.at(j) == element)
		{
			contains = true;
			break;
		}
	}
	return contains;
}

int main()
{
	map<string, int> ores;

	vector<string> order;
	string ore;
	int i = 0;
	while (true)
	{
		string input;
		getline(cin >> ws, input);

		if (input == "stop") break;

		if (++i % 2 == 0)
		{
			ores[ore] += stoi(input);
			if (!contains(order, ore))
			{
				order.push_back(ore);
			}
		}
		else
		{
			ore = input;
		}
	}

	for (int j = 0; j < order.size(); j++)
	{
		for (auto const& keyValue : ores)
		{
			if (order.at(j) != keyValue.first) continue;
			cout << keyValue.first << " -> " << keyValue.second << endl;
		}
	}
}