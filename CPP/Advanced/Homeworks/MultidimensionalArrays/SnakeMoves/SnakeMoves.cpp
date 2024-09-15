#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int rows, cols;
	string snake;
	cin >> rows >> cols;
	cin >> snake;
	
	queue<char> myQue;
	int counter = 0;
	int capacity = rows * cols;

	for (int i = 0; i < snake.size(); i++)
	{
		myQue.push(snake[i]);
		counter++;

		if (counter == capacity)
		{
			break;
		}

		if (i == snake.size() - 1)
		{
			i = -1;
		}
	}

	vector<vector<char>> matrix(rows, vector<char>(cols));

	for (int j = 0; j < rows; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < cols; i++)
			{
				matrix[j][i] = myQue.front();
				myQue.pop();
			}
		}
		else if (j % 2 != 0)
		{
			for (int k = cols - 1; k > -1; k--)
			{
				matrix[j][k] = myQue.front();
				myQue.pop();
			}
		}

	}

	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix[row].size(); col++)
		{
			cout << matrix[row][col];
		}
		cout << endl;
	}
}
