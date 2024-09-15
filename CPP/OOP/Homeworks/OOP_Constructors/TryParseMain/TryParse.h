#ifndef TRYPARSE_H
#define TRYPARSE_H

#include <string>
#include <istream>

using namespace std;

bool isInteger(const string& s) {
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
		return false;
	}

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

bool tryParse(string text, int& number)
{
	if (isInteger(text))
	{
		number = stoi(text);
		return true;
	}
	return false;
}

#endif // !TRYPARSE_H

