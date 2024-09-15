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


}
