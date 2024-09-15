#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

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

int main()
{
    string input;
    getline(cin, input);

    int currentValue = 0;
    int previousValue = 0;
    vector<string> something = split(input, " ");

    for (int i = 0; i < something.size(); i++)
    {
        int pv = currentValue;
        if (something[i] == "+")
        {
            currentValue = previousValue + currentValue;
            previousValue = pv;
        }
        else if (something[i] == "-")
        {
            currentValue = previousValue - currentValue;
            previousValue = pv;
        }
        else if (something[i] == "*")
        {
            currentValue = previousValue * currentValue;
            previousValue = pv;
        }
        else if (something[i] == "/")
        {
            currentValue = previousValue / currentValue;
            previousValue = pv;
        }
        else
        {
            previousValue = pv;
            currentValue = stoi(something[i]);
        }
    }

    cout << currentValue << " " << previousValue << endl;
}
