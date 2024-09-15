#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include "HasId.h"
#include "HasInfo.h"

using namespace std;

class Company : public HasId, public HasInfo {
public:
	int id;
	string name;
	vector<pair<char, char>> employees;
	Company();
	Company(int id, string name, vector<pair<char, char>> employees);
	int getId() const override;
	string getName() const;
	vector<pair<char, char>> getEmployees() const;
	string getInfo() const override;
};

ostream& operator<<(ostream& stream, const Company& c);
istream& operator>>(istream& stream, Company& c);

#endif // COMPANY_H