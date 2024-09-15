#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int pushCount, popCount, specialN;

	queue<int> queue;

	cin >> pushCount >> popCount >> specialN;

	for (int i = 0; i < pushCount; i++)
	{
		int number;
		cin >> number;
		queue.push(number);
	}

	for (int i = 0; i < popCount; i++)
	{
		queue.pop();
	}

	bool result = false;
	int smallest = queue.size() > 0 ? INT32_MAX : 0;
	while (queue.size() > 0)
	{
		int top = queue.front();
		if (smallest > top)
		{
			smallest = top;
		}

		if (top == specialN)
		{
			result = true;
		}
		queue.pop();
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