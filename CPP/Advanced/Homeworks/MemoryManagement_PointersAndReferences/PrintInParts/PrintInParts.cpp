#include <iostream>
#include <vector>

using namespace std;

void readMatrix(istream& input, vector<vector<int>>& matrix, int& rows, int& cols)
{
	input >> rows >> cols;

	matrix.resize(rows, vector<int>(cols, 0));

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

int main()
{
	int rows, cols;
	vector<vector<int>> matrix;
	readMatrix(cin, matrix, rows, cols);

	int r, c;
	cin >> r >> c;

	for (int row = 0; row < r; row++)
	{
		for (int col = 0; col < c; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}
