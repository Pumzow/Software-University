#include <iostream>
#include <string>
#include <array>
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

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void fillMatrix(char matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	for (int col = 0; col < cols; ++col)
	{
		string input;
		getline(cin >> ws, input);
		vector<string> info = split(input, " ");
		for (int row = 0; row < info.size(); ++row)
		{
			matrix[col][row] = info[row][0];
		}
	}
}

void findMatrixSquares(char matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	int squares = 0;
	for (int i = 0; i < rows - 1; ++i)
	{
		for (int j = 0; j < cols - 1; ++j)
		{
			if (matrix[i][j] == matrix[i + 1][j] &&
				matrix[i][j] == matrix[i][j + 1] &&
				matrix[i][j] == matrix[i + 1][j + 1])
			{
				squares++;
			}
		}
	}
	cout << squares;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;
	char matrix[MAX_ROWS][MAX_COLS];
	fillMatrix(matrix, cols, rows);
	findMatrixSquares(matrix, rows, cols);
}
