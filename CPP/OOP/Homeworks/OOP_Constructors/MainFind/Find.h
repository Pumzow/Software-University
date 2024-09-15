#ifndef FIND_H

#define FIND_H

#include "Company.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Company* find(vector<Company*> & companies, int seatchId)
{
	for (size_t i = 0; i < companies.size(); i++)
	{
		Company* company = companies.at(i);
		if (company->getId() == seatchId)
		{
			return company;
		}
	}
	return nullptr;
}

#endif // !FIND_H