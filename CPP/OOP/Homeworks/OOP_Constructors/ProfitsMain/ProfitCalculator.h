#ifndef PROFIT_CALCULATOR_H
#define PROFIT_CALCULATOR_H

#include <istream>
#include "Company.h"

using namespace std;

class ProfitCalculator {
private:
	int taxPercentage;
public:
	int calculateProfit(const Company& company) const {
		int balance = company.getRevenue() - company.getCosts();
		int tax = (balance * taxPercentage) / 100;
		return balance - tax;
	}

	friend istream& operator>>(istream& stream, ProfitCalculator& p);
};

istream& operator>>(istream& stream, ProfitCalculator& p) {
	return stream >> p.taxPercentage;
}

#endif
