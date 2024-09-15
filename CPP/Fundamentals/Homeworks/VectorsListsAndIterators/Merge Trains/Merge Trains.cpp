#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<stack>
#include <queue>

using namespace std;

vector<int> readFunction(string passedString) {
    vector<int> rail;
    stringstream iss(passedString);
    int number;
    while (iss >> number)
    { 
        rail.push_back(number);
    }
    return rail;
}

int main() {

    vector<int> railA;
    vector<int> railB;
    string input;

    getline(cin, input);
    railA = readFunction(input);
    getline(cin, input);
    railB = readFunction(input);


    priority_queue<int> Result;
    vector<char> TrainChar;

    for (int i : railA) 
    { 
        Result.push(i); 
    }
    for (int i : railB)
    {
        Result.push(i); 
    }

    while (!Result.empty()) 
    {
        if (find(railA.begin(), railA.end(), Result.top()) != railA.end())
        {
            TrainChar.push_back('A');
        }
        else 
        { 
            TrainChar.push_back('B'); 
        }
        Result.pop();
    }

    for (int n = TrainChar.size() - 1; n >= 0; n--) 
    { 
        cout << TrainChar[n];
    }  
    cout << endl;
    vector<int> train(railA.size() + railB.size());
    merge(railA.begin(), railA.end(), railB.begin(), railB.end(), train.begin());
    sort(train.begin(), train.end(), greater<int>());
    for (auto n : train) 
    {
        cout << n << " "; 
    }
}