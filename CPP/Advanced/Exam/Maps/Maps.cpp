#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>

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
	matrix.resize(rows, vector<int>(cols, 0));

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cin >> matrix[row][col];
		}
	}
}


int getDistance(vector<vector<int>>& matrix, int fromIndex, int toIndex)
{
	return matrix[fromIndex][toIndex];
}

int main()
{
	vector<string> bodies;

	while (true)
	{
		string input;
		cin >> input;
		if (input == "END") break;
		bodies.push_back(input);
	}

	int rows = bodies.size(), cols = bodies.size();
	vector<vector<int>> matrix;
	readMatrix(cin, matrix, rows, cols);

	vector<vector<int>> paths;
	while (true)
	{
		string input;
		getline(cin >> ws, input);
		vector<string> info = split(input, " ");

		if (info.at(0) == "END") break;

		vector<int> path;
		for (int i = 0; i < info.size(); i++)
		{
			for (int j = 0; j < bodies.size(); j++)
			{
				if (bodies.at(j) == info.at(i)) 
				{
					path.push_back(j);
					break;
				}
			}
		}
		paths.push_back(path);
	}

	set<int> distances;
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix.at(row).size(); col++)
		{
			if (row == col) continue;
			distances.insert(getDistance(matrix, row, col));
		}
	}
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix.at(row).size(); col++)
		{
			int distance = *distances.begin();
			if (getDistance(matrix, row, col) == distance)
			{
				cout << distance << ": " << bodies.at(row) << " -> " << bodies.at(col) << endl;
			}
		}
	}
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix.at(row).size(); col++)
		{
			int distance = *distances.rbegin();
			if (getDistance(matrix, row, col) == distance)
			{
				cout << distance << ": " << bodies.at(row) << " -> " << bodies.at(col) << endl;
			}
		}
	}

	int totalSum = 0;
	for (auto p : paths)
	{
		int sum = 0;
		for (size_t i = 0; i < p.size() - 1; i++)
		{
			sum += getDistance(matrix, p.at(i), p.at(i+1));
		}
		cout << sum << endl;
		totalSum += sum;
	}
	cout << totalSum << endl;
}
