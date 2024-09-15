#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> numbers;

	while (true)
	{
		string input;
		cin >> input;

		if (input == "sum")
		{
			int sum = numbers.at(numbers.size() -1) + numbers.at(numbers.size() - 2);

			numbers.pop_back();
			numbers.pop_back();
			numbers.push_back(sum);
		}
		else if(input == "subtract")
		{
			int subraction = numbers.at(numbers.size()- 1) - numbers.at(numbers.size() - 2);

			numbers.pop_back();
			numbers.pop_back();
			numbers.push_back(subraction);
		}
		else if (input == "discard")
		{
			numbers.pop_back();
		}
		else if (input == "concat")
		{
			string number1 = to_string(numbers.at(numbers.size() - 2));
			string number2 = to_string(numbers.at(numbers.size() - 1));
			string result = number1 + number2;
			numbers.pop_back();
			numbers.pop_back();
			numbers.push_back(stoi(result));

		}
		else if(input == "end")
		{
			break;
		}
		else
		{
			numbers.push_back(stoi(input));
		}
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}
}
