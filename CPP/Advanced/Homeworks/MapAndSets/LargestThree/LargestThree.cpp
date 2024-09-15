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

int main()
{
	string input;
	getline(cin >> ws, input);
	vector<string> numbers = split(input, " ");

	map<double, int, greater<int>> numbersCount;

	for (int i = 0; i < numbers.size(); i++)
	{
        numbersCount[stod(numbers.at(i))]++;
	}

    string separator = ""; 
    if (numbersCount.size() < 3)
    {
        for (auto const& x : numbersCount)
        {
            cout << separator << x.first;
            separator = " ";
        }
        return 1;
    }

    int k = 3;
    for (auto const& x : numbersCount)
    {
        if (k <= 0) continue;

        cout << separator << x.first;
        separator = " ";
        k--;
    }
}