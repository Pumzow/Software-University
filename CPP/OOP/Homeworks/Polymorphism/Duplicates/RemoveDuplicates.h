#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include <list>
#include <unordered_set>
#include "Company.h"

void removeDuplicates(std::list<Company*>& companies) {
    std::unordered_set<std::string> uniqueNames;
    auto it = companies.begin();
    while (it != companies.end()) {
        if (uniqueNames.find((*it)->getName()) == uniqueNames.end()) {
            // This is a unique company, add its name to the set
            uniqueNames.insert((*it)->getName());
            ++it;
        }
        else {
            // This is a duplicate company, delete it and remove its pointer from the list
            delete* it;
            it = companies.erase(it);
        }
    }
}

#endif // REMOVE_DUPLICATES_H