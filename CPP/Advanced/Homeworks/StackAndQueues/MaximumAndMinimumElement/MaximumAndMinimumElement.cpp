#include <iostream>
#include <string>
#include <queue>
#include <stack>

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
	int n;
	stack<int> numbers;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin >> ws, input);
		vector<string> commands = split(input, " ");

		int command = stoi(commands.at(0));
		if (command == 1)
		{
			int number = stoi(commands.at(1));
			numbers.push(number);
		}
		else if (command == 2)
		{
			numbers.pop();
		}
		else if (command == 3)
		{
			if (numbers.size() <= 0) continue;
			stack<int> numbersCopy = numbers;
			priority_queue<int> maximumNumbers;
			while(numbersCopy.size() > 0)
			{
				maximumNumbers.push(numbersCopy.top()); numbersCopy.pop();
			}

			cout << maximumNumbers.top() << endl;
		}
		else if (command == 4)
		{
			if (numbers.size() <= 0) continue;
			stack<int> numbersCopy = numbers;
			priority_queue<int, vector<int>, greater<int> > minimumNumbers;
			while (numbersCopy.size() > 0)
			{
				minimumNumbers.push(numbersCopy.top()); numbersCopy.pop();
			}

			cout << minimumNumbers.top() << endl;
		}
	}

	while(numbers.size() > 0)
	{
		if (numbers.size() > 1)
		{
			cout << numbers.top() << ", ";
		}
		else
		{
			cout << numbers.top();
		}
		numbers.pop();
	}
}