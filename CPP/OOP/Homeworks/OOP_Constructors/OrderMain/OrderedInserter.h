#ifndef ORDERED_INSERTER_H

#define ORDERED_INSERTER_H

#include "Company.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class OrderedInserter
{
private:

	vector<const Company*>& companies;

public:
	OrderedInserter(vector<const Company*>& companies) : companies(companies)
	{}

	void insert(const Company* c)
	{
        auto it = this->companies.begin();
        while (it != this->companies.end()) 
        {
            if ((*it)->getId() > c->getId())
            {
                this->companies.insert(it, c);
                return;
            }
            ++it;
        }
        this->companies.push_back(c);
	}
};

#endif // !ORDERED_INSERTER_H