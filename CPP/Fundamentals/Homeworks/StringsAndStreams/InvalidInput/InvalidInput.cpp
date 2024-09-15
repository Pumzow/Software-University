#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    istringstream ss(input);

    vector<string> terms, words;
    while (ss) {
        string s;
        ss >> s;
        if (s != "") terms.push_back(s);
    }

    int sum = 0;
    for (string s : terms)
    {
        int x;
        try {
            x = std::stoi(s);
            sum += x;
        }
        catch (std::invalid_argument) {
            words.push_back(s);
        }
    }

    cout << sum << "\n";
    for (auto w : words) cout << w << " ";
}