#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include <map>
#include <sstream>
#include "Company.h"
#include "ProfitCalculator.h"

using namespace std;

string getProfitReport(const Company* fromInclusive,
    const Company* toInclusive,
    const map<int, ProfitCalculator>& profitCalculatorsByCompany)
{
    ostringstream oss;
    const Company* current = fromInclusive;
    while (true) {
        oss << current->getName()
            << " = "
            << profitCalculatorsByCompany.at(current->getId()).calculateProfit(*current)
            << endl;
        if (current == toInclusive) {
            break;
        }
        ++current;
    }
    return oss.str();
}

#endif