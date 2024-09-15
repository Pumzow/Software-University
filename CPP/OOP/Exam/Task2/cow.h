#ifndef COW_H
#define COW_H

#include "animal.h"
#include <iostream>
#include <sstream>

using namespace std;

class Cow : public Animal {

    unsigned litersPerDay;

public:
    Cow(istream& istr) : litersPerDay(0) {
        istr >> litersPerDay;
    }

    virtual unsigned getResult(unsigned weeks) const {
        return litersPerDay * 7 * weeks;
    };

    virtual string getDescription() const { return "Cow"; }

    virtual string getInfo() const {
        ostringstream ostr;
        ostr << '<' << litersPerDay << ">";
        return ostr.str();
    }
};
#endif