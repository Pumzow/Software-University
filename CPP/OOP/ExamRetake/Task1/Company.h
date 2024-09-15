#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <memory>

using namespace std;

class Company {
public:
    int id;
    string name;
    vector<pair<char, char>> employees;

    Company();
    Company(int id, string name, vector<pair<char, char>> employees);

    int getId() const;
    string getName() const;
    vector<pair<char, char>> getEmployees() const;
    string getInfo() const;
    virtual bool isSuper(void) const { return false; } 

    friend ostream& operator<<(ostream& stream, const Company& c);
    friend istream& operator>>(istream& stream, Company& c);
};
#endif