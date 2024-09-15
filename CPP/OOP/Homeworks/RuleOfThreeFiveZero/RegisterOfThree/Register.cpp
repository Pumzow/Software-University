#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) {}

void Register::add(const Company& c) {
    companiesArray[numAdded++] = c;
}

Company Register::get(int companyId) const {
    for (size_t i = 0; i < numAdded; ++i) {
        if (companiesArray[i].getId() == companyId) {
            return companiesArray[i];
        }
    }
    return Company();
}

Register::~Register() {
    delete[] companiesArray;
}

Register::Register(const Register& other) : numAdded(other.numAdded) {
    companiesArray = new Company[numAdded];
    for (size_t i = 0; i < numAdded; ++i) {
        companiesArray[i] = other.companiesArray[i];
    }
}

Register& Register::operator=(const Register& other) {
    if (this != &other) {
        delete[] companiesArray;

        numAdded = other.numAdded;
        companiesArray = new Company[numAdded];
        for (size_t i = 0; i < numAdded; ++i) {
            companiesArray[i] = other.companiesArray[i];
        }
    }
    return *this;
}
