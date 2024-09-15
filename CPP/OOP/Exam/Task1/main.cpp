#include "Solution.h"
#include "BaseStudent.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

int main() {
    vector<shared_ptr<Student>> data;

    string buffer;
    while (getline(cin, buffer)) {
        if (buffer.empty()) continue;
        if (data.size() > 0 && data[0]->isEndInput(buffer)) break;

        if (!readStudent(data, buffer)) break;
    }

    // initialize the fixed output
    vector<string> fixedOutputs;
    fixedOutputs.resize(10);
    for (size_t cnt = 0; cnt <= 9; cnt++) {
        ostringstream ostr;
        ostr << cnt * 10 << ".." << cnt * 10 + 9;
        fixedOutputs[cnt] = ostr.str();
    }

    auto totals = processStudents(data);

    for (size_t cnt = 0; cnt <= 9; cnt++)
        cout << fixedOutputs[cnt] << " => " << totals[cnt] << endl;

    return 0;
}