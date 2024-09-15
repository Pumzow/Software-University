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

//void fillMatrix(vector<vector<int>>& matrix, int rows, int cols) {
//	for (int i = 0; i < rows; ++i) 
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			matrix[i][j] = i * cols + j + 1;
//		}
//	}
//}

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void initializeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			matrix[row][col] = 0;
		}
	}
}

void fillMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	for (int col = 0; col < cols; ++col)
	{
		string input;
		getline(cin >> ws, input);
		vector<string> info = split(input, " ");
		for (int row = 0; row < info.size(); ++row)
		{
			matrix[col][row] = stoi(info[row]);
		}
	}
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS])
{
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		for (int j = 0; j < MAX_COLS; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void findMatrixElement(int matrix[MAX_ROWS][MAX_COLS], int element)
{
	bool found = false;
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		for (int j = 0; j < MAX_COLS; ++j)
		{
			if (matrix[i][j] == element)
			{
				cout << i << " "<< j << endl;
				found = true;
			}
		}
	}
	if (found) return;
	cout << "not found";
}

void compareMatrixes(int matrix[MAX_ROWS][MAX_COLS], int matrix1[MAX_ROWS][MAX_COLS])
{
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		for (int j = 0; j < MAX_COLS; ++j)
		{
			if (matrix[i][j] != matrix1[i][j])
			{
				cout << "not equal";
				return;
			}
		}
	}
	cout << "equal";
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;
	int matrix[MAX_ROWS][MAX_COLS];
	initializeMatrix(matrix, MAX_ROWS, MAX_COLS);
	fillMatrix(matrix, cols, rows);
	int element;
	cin >> element;
	findMatrixElement(matrix, element);
}
