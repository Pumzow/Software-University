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
	int foodQuantity;
	cin >> foodQuantity;

	string input;
	getline(cin >> ws, input);
	vector<string> orders = split(input, " ");

	stack<int> numbers;
	for (int i = 0; i < orders.size(); i++)
	{
		numbers.push(stoi(orders.at(i)));
	}
	stack<int> numbersCopy = numbers;
	priority_queue<int> orderedOrders;

	while (!numbers.empty())
	{
		numbers.pop();
	}

	while (!numbersCopy.empty())
	{
		orderedOrders.push(numbersCopy.top());
		numbers.push(numbersCopy.top());
		numbersCopy.pop();
	}

	cout << orderedOrders.top() << endl;

	while (true)
	{
		if (numbers.empty()) break;
		if (foodQuantity >= numbers.top())
		{
			foodQuantity -= numbers.top();
			numbers.pop();
		}
		else
		{
			break;
		}
	}

	if (numbers.empty())
	{
		cout << "Orders complete" << endl;
	}
	else
	{
		cout << "Orders left: ";
		while (!numbers.empty())
		{
			cout << numbers.top() << " ";
			numbers.pop();
		}
	}
}