#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

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

void fillMatrix(vector<vector<int>>& matrix, int rows, int cols)
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

void printMatrix(vector<vector<int>>& matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int sum3x3(vector<vector<int>>& matrix, int startRow, int startCol)
{
    int sum = 0;

    for (int row = startRow; row < startRow + 3; row++)
    {
        for (int col = startCol; col < startCol + 3; col++)
        {
            sum += matrix[row][col];
        }
    }

    return sum;
}

void readMatrix(istream & input, vector<vector<int>> & matrix, int & rows, int & cols)
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

void printReverseDiagonal(const vector<vector<int>>& matrix, int startRow, int startCol)
{
    while (startRow >= 0 && startCol < matrix[0].size())
    {
        cout << matrix[startRow][startCol] << " ";
        startRow--; startCol++;
    }
    cout << endl;
}

int main()
{
    int rows, cols;
    vector<vector<int>> matrix;
    readMatrix(cin, matrix, rows, cols);

    for (int col = cols - 1; col >= 0; col--)
    {
        printReverseDiagonal(matrix, rows - 1, col);
    }

    for (int row = rows - 2; row >= 0; row--)
    {
        printReverseDiagonal(matrix, row, 0);
    }

}
