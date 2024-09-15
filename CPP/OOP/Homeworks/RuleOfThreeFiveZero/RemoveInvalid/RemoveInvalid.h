#ifndef REMOVE_INVALID_H

#define REMOVE_INVALID_H

#include "Company.h"
#include <vector>

using namespace std;

void removeInvalid(list<Company*>& companies)
{
    companies.remove_if([](Company* company) {
        return company->getId() < 0;
        });
}

#endif // !REMOVE_INVALID_H