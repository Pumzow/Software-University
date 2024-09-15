#ifndef SORT_BY_H

#define SORT_BY_H

#include "Company.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename Comparator>
void sortBy(Company** companyFirst, Company** companyLast, Comparator comp)
{
    std::sort(companyFirst, companyLast, [&](Company* a, Company* b) {
        return comp(*a, *b);
        });
}
#endif // !SORT_BY_H