#include "storage.h"

// Check if storage contains all elements of contents
bool Storage::operator<=(Store& contents) {
    for (auto& elem : contents) {
        if (storage[elem.first] < elem.second) {
            return false;
        }
    }
    return true;
}

// Remove elements specified in contents from the storage
Storage& Storage::operator>>(Store& contents) {
    for (auto& elem : contents) {
        if (storage[elem.first] >= elem.second) {
            storage[elem.first] -= elem.second;
            if (storage[elem.first] == 0) {
                storage.erase(elem.first);
            }
        }
        else {
            // Handle the case where there are not enough elements to remove
            std::cerr << "Error: Trying to remove more elements than available in storage" << std::endl;
        }
    }
    return *this;
}

// Stream insertion operator to print Storage contents
std::ostream& operator<<(std::ostream& os, const Storage& storage) {
    if (storage.storage.empty()) {
        os << "Storage: Empty";
    }
    else {
        os << "Storage: ";
        bool first = true;
        for (const auto& elem : storage.storage) {
            if (!first) {
                os << ", ";
            }
            os << elem.first << ": " << elem.second;
            first = false;
        }
    }
    return os;
}
