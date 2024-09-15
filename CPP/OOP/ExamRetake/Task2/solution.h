#include "storage.h"

// Check if storage contains all elements of contents
bool Storage::operator<=(Store& contents) {
    for (auto& elem : contents) {
        if (storage.find(elem.first) == storage.end() || storage[elem.first] < elem.second) {
            return false;
        }
    }
    return true;
}

// Remove elements specified in contents from the storage
Storage& Storage::operator>>(Store& contents) {
    if (*this <= contents) {
        for (auto& elem : contents) {
            if (storage[elem.first] >= elem.second) {
                storage[elem.first] -= elem.second;
                if (storage[elem.first] == 0) {
                    storage.erase(elem.first);
                }
            }
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
        bool isFirstElement = true;
        for (const auto& elem : storage.storage) {
            if (!isFirstElement) {
                os << ", ";
            }
            os << elem.first << ": " << elem.second;
            isFirstElement = false;
        }
    }
    return os;
}
