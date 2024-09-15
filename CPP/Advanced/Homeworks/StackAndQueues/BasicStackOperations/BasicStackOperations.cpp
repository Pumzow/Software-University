#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int pushCount, popCount, specialN;

	stack<int> stack;

	cin >> pushCount >> popCount >> specialN;

	for (int i = 0; i < pushCount; i++)
	{
		int number;
		cin >> number;
		stack.push(number);
	}

	for (int i = 0; i < popCount; i++)
	{
		stack.pop();
	}

	bool result = false;
	int smallest = stack.size() > 0 ? INT32_MAX : 0;
	while(stack.size() > 0)
	{
		int top = stack.top();
		if (smallest > top)
		{
			smallest = top;
		}

		if (top == specialN) 
		{
			result = true;
		}
		stack.pop();
	}

	if (result)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << smallest << endl;
	}
}
