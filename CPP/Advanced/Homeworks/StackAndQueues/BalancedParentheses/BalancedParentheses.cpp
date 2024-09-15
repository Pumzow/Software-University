#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "BalancedParentheses.h"

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
	vector<char> brackets = { '(', '{', '[' };

	string input;
	cin >> input;

	vector<char> chars;
	for (int i = 0; i < input.length(); i++)
	{
		chars.push_back(input.at(i));
	}
	bool valid = true;
	stack<char> stack;
	for (int i = 0; i < chars.size(); i++)
	{
		char bracket = chars.at(i);
		if (contains(brackets, bracket))
		{
			stack.push(bracket);
			continue;
		}

		if (stack.size() == 0)
		{
			valid = false;
			break;
		}
		if (stack.top() == '(' && bracket == ')')
		{
			stack.pop();
		}
		else if (stack.top() == '[' && bracket == ']')
		{
			stack.pop();
		}
		else if (stack.top() == '{' && bracket == '}')
		{
			stack.pop();
		}
		else
		{
			valid = false;
			break;
		}
	}

	if (valid)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}