#include "IndexedSet.h"
#include <algorithm>

IndexedSet::IndexedSet() : valuesArray(nullptr) {}

IndexedSet::IndexedSet(const IndexedSet& other) : valuesSet(other.valuesSet), valuesArray(nullptr) {}

void IndexedSet::add(const Value& v) {
    valuesSet.insert(v);
    clearIndex();
}

size_t IndexedSet::size() const {
    return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
    if (!valuesArray) {
        buildIndex();
    }
    return valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
    if (this != &other) {
        valuesSet = other.valuesSet;
        clearIndex();
    }
    return *this;
}

IndexedSet::~IndexedSet() {
    clearIndex();
}

void IndexedSet::buildIndex() {
    valuesArray = new Value[valuesSet.size()];
    size_t i = 0;
    for (const auto& value : valuesSet) {
        valuesArray[i++] = value;
    }
    std::sort(valuesArray, valuesArray + valuesSet.size());
}

void IndexedSet::clearIndex() {
    delete[] valuesArray;
    valuesArray = nullptr;
}
