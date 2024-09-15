#ifndef SUMOFVECTORS_H

#define SUMOFVECTORS_H

#include <string>
#include <vector>

using namespace std;

vector<string> operator+(vector<string> &a, vector<string>& b)
{
	vector<string> result;
	for (size_t i = 0; i < a.size(); i++)
	{
		result.push_back(a.at(i) + " " + b.at(i));
	}

	return result;
}

#endif // !SUMOFVECTORS_H