#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

vector<string> split(string s, string sep)
{
    vector<string> results;
    auto pos = s.find(sep);
    while (pos != -1)
    {
        string token = s.substr(0, pos);
        results.push_back(token);
        s = s.substr(pos + sep.size());
        pos = s.find(sep);
    }
    results.push_back(s);
    return results;
}

bool isSquareNumber(int n)
{
    return ceil((double)sqrt(n)) == floor((double)sqrt(n));
}

int main()
{
    string input;
    getline(cin >> ws, input);
    vector<string> numbers = split(input, " ");
    vector<int> result;

    for (int i = 0; i < numbers.size(); i++)
    {
        int number = stoi(numbers.at(i));
        if (!isSquareNumber(number)) continue;

        result.push_back(number);
    }
    
    sort(result.begin(), result.end(), greater<int>());
    string separator = "";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << separator << result.at(i);
        separator = " ";
    }
}
