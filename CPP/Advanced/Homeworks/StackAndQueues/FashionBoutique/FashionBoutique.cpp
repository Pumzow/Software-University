#include <iostream>
#include <string>
#include <queue>
#include <stack>

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
    getline(cin >> ws, input);
    vector<string> orders = split(input, " ");
    vector<int> priceOfClothes;
    stack<int> prices;
    for (int i = 0; i < orders.size(); i++)
    {
        priceOfClothes.push_back(stoi(orders.at(i)));
        prices.push(stoi(orders.at(i)));
    }

    int rackCapacity;
    cin >> rackCapacity;

    int sumOfClothes = 0;
    int numOfRacks = 1;

    for (int i = priceOfClothes.size() - 1; i >= 0; i--)
    {
        sumOfClothes += priceOfClothes[i];

        if (sumOfClothes <= rackCapacity)
        {
            if (!prices.empty())
            {
                prices.pop();
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            i++;
            numOfRacks++;
            sumOfClothes = 0;
        }
    }

    cout << numOfRacks << endl;
}
