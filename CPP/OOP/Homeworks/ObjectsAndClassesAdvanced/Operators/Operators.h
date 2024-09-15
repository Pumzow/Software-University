#ifndef OPERATORS_H

#define OPERATORS_H
#include <ostream> 
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

vector<string> & operator<<(vector<string> &a, const string & b)
{
	a.push_back(b);
	return a;
}

string operator+(string& a, int b)
{
	ostringstream ostr;
	ostr << a << b;
	return ostr.str();
}

ostream& operator << (ostream& a, const vector<string>& b)
{
	for (size_t i = 0; i < b.size(); i++)
	{
		a << b.at(i) << endl;
	}
	return a;
}

#endif // !OPERATORS_H