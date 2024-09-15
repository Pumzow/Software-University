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
    int n;
    cin >> n;
    queue<int> queueTruck;
    for (int i = 0; i < n; i++)
    {
        string input;
        getline(cin >> ws, input);
        vector<string> info = split(input, " ");
        int amountOfPetrol = stoi(info.at(0));
        int distance = stoi(info.at(1));

        queueTruck.push(amountOfPetrol - distance);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (queueTruck.front() >= 0)
        {
            queue<int> queueTruckCopy = queueTruck;
            while (!queueTruckCopy.empty())
            {
                sum += queueTruckCopy.front();
                if (sum < 0) break;
                queueTruckCopy.pop();
            }

            if (sum >= 0)
            {
                cout << i << endl;
                return 1;
            }
            else
            {
                queueTruck.push(queueTruck.front());
                queueTruck.pop();
                sum = 0;
            }
        }
        else
        {
            queueTruck.push(queueTruck.front());
            queueTruck.pop();
        }
    }
}