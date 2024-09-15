#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include <iostream>
#include <sstream>

using namespace std;

class Dog : public Animal {

    unsigned catsPerHour;
    unsigned activeHours;

public:
    Dog(istream& istr) : catsPerHour(0), activeHours(0) {
        istr >> catsPerHour >> activeHours;
    }

    virtual unsigned getResult(unsigned weeks) const {
        return catsPerHour * activeHours * 7 * weeks;
    };

    virtual string getDescription() const { return "Dog"; }

    virtual string getInfo() const {
        ostringstream ostr;
        ostr << '<' << catsPerHour << ", " << activeHours << ">";
        return ostr.str();
    }
};
#endif