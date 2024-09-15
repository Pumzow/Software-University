#ifndef BASESTUDENT_H
#define BASESTUDENT_H

#include <iostream>
#include <string>

using namespace std;

class BaseStudent {

protected:
    string name;
    int grade;

public:
    BaseStudent() : name(), grade(0) {}
    virtual ~BaseStudent() {}

    virtual void init(istream& iS) = 0;
    virtual bool isEndInput(const string& input) const = 0;

    int getGrade() const { return grade; }
    const string& getName() const { return name; }
};
#endif