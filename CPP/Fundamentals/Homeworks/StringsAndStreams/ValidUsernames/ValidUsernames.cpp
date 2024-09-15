#include <iostream>
#include <string>
#include <vector>
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
    auto items = split(input, ", ");

    for (auto user : items)
    {
        if (user.size() < 3 || user.size() > 16) continue;
        bool isValid = true;
        for (auto c : user)
        {
            if (!(isalnum(c) || c == '-' || c == '_')) isValid = false;
        }
        if (isValid) cout << user << endl;
    }


}