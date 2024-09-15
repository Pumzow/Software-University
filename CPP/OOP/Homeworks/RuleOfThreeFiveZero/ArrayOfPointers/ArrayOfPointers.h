#ifndef ARRAY_OF_POINTERS_H
#define ARRAY_OF_POINTERS_H

#include "Company.h"
#include <vector>

class ArrayOfPointers {
private:
    std::vector<Company*> companies;

public:
    ArrayOfPointers() {}

    ~ArrayOfPointers() {
        for (auto& company : companies) {
            delete company;
        }
    }

    void add(Company* company) {
        companies.push_back(company);
    }

    Company* get(size_t index) const {
        if (index < companies.size()) {
            return companies[index];
        }
        else {
            return nullptr;
        }
    }

    size_t getSize() const {
        return companies.size();
    }
};

#endif // ARRAY_OF_POINTERS_H
