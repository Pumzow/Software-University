#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Range {
    int from, to;
};

inline bool isInRange(int num, int from, int to) {
    return num >= from && num <= to;
}

int main() {
    constexpr int MAX_RANGES = 10000;
    Range ranges[MAX_RANGES];
    int numRanges = 0;

    string input;

    while (getline(cin >> ws, input) && input != ".") {
        istringstream iss(input);
        int from, to;
        if (iss >> from >> to) {
            ranges[numRanges++] = { from, to };
        }
    }

    while (getline(cin >> ws, input) && input != ".") {
        int num = stoi(input);
        bool isInAnyRange = false;
        for (int i = 0; i < numRanges; ++i) {
            if (isInRange(num, ranges[i].from, ranges[i].to)) {
                isInAnyRange = true;
                break;
            }
        }
        cout << (isInAnyRange ? "in" : "out") << endl;
    }

    return 0;
}
