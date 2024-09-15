#ifndef MIN_BY_H
#define MIN_BY_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template< typename Comparator>
const string& minBy(const vector<string>& values, Comparator comp) {
    return *min_element(values.begin(), values.end(), comp);
}

#endif // !MIN_BY_H