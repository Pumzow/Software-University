#include <iostream>
#include <vector>

using namespace std;

vector<int> parsePipes(int pipesCount);

int parseInt();

int main() {
    const int pipesCount = parseInt();
    const vector<int> pipesOld = parsePipes(pipesCount);
    const vector<int> pipesNew = parsePipes(pipesCount);

    for (int i = 0; i < pipesCount; ++i) {
        int yearsLeft = pipesNew[i] / (pipesNew[i] - pipesOld[i]);
        cout << yearsLeft << " ";
    }

    return 0;
}

int parseInt() {
    int value;
    cin >> value;
    return value;
}

vector<int> parsePipes(const int pipesCount) {
    vector<int> pipes;
    for (int i = 0; i < pipesCount; ++i) {
        pipes.emplace_back(parseInt());
    }
    return pipes;
}