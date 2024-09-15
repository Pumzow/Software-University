#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input, find, replace;
    getline(cin, input);
    getline(cin, find);
    getline(cin, replace);
    string output;

    output = input;
    while (output.find(find) != -1)
        output = output.replace(output.find(find), find.size(), replace);

    cout << output;
}