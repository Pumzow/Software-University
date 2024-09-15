#ifndef PARSE_COMPANIES_H

#define PARSE_COMPANIES_H

#include "Company.h"

using namespace std;

template< typename Comparator>
Company* parseUniqueCompanies(const string text, int& numCompanies, Comparator comp)
{
    vector<Company> uniqueCompanies;

    istringstream iss(text);
    string line;
    while (getline(iss, line)) {
        istringstream lineStream(line);
        int id;
        string name;
        lineStream >> id >> name;

        bool foundCompany = false;
        for (const auto& company : uniqueCompanies) {
            if (comp(company) == comp(Company(id, name))) {
                foundCompany = true;
                break;
            }
        }

        if (!foundCompany) {
            uniqueCompanies.push_back(Company(id, name));
        }
    }

    numCompanies = uniqueCompanies.size();

    Company* companiesArray = new Company[numCompanies];
    copy(uniqueCompanies.begin(), uniqueCompanies.end(), companiesArray);
    return companiesArray;
}

#endif // !PARSE_COMPANIES_H