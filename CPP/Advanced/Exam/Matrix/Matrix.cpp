#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readMatrix(istream& input, vector<vector<char>>& matrix, int& rows, int& cols)
{
    //input >> rows >> cols;

    matrix.resize(rows, vector<char>(cols, 0));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cin >> matrix[row][col];
        }
    }
}

void PrintFigures(std::vector<char>& whites, std::vector<char>& blacks)
{

    if (whites.empty())
    {
        cout << "<no white figures>" << endl;
    }
    else
    {
        for (size_t i = 0; i < whites.size(); i++)
        {
            cout << whites.at(i);
        }
        cout << endl;
    }
    if (blacks.empty())
    {
        cout << "<no black figures>" << endl;
    }
    else
    {
        for (size_t i = 0; i < blacks.size(); i++)
        {
            cout << blacks.at(i);
        }
        cout << endl;
    }
}

int main()
{
    int rows = 8, cols = 8;
    vector<vector<char>> matrix;
    readMatrix(cin, matrix, rows, cols);

    vector<char> whites;
    vector<char> blacks;

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            if (isupper(matrix[row][col]))
            {
                whites.push_back(matrix[row][col]);
            }
            else if(matrix[row][col] != '.')
            {
                blacks.push_back(matrix[row][col]);
            }
        }
    }
    
    PrintFigures(whites, blacks);

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            if (isupper(matrix[row][col]))
            {
                matrix[row][col] = tolower(matrix[row][col]);
            }
            else
            {
                matrix[row][col] = toupper(matrix[row][col]);
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
