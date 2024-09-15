#include <iostream>
#include <stack>
#include <queue>
#include <string>

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
	queue<string> queue1;
	queue<string> queue2;
	stack<string> rowOfChairs;

	while (true)
	{
        string input;
        getline(cin >> ws, input);
        vector<string> info = split(input, " ");

        if (info.at(0) == "5") break;
        if (info.at(0) == "10")
        {
            queue1.pop();
        }
        else if (info.at(0) == "20")
        {
            queue2.pop();
        }
        else if (info.at(0) == "12")
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        else if (info.at(0) == "23")
        {
            rowOfChairs.push(queue2.front());
            queue2.pop();
        }
        else if (info.at(0) == "31")
        {
            queue1.push(rowOfChairs.top());
            rowOfChairs.pop();
        }
        else if (info.at(0) == "99")
        {
            cout << "1:";
            queue<string> queueCopy = queue1;
            if (queueCopy.empty())
            {
                cout << " <empty>";
            }
            else
            {
                while (!queueCopy.empty())
                {
                    cout << " " << queueCopy.front();
                    queueCopy.pop();
                }
            }
            cout << endl;
            cout << "2: ";
            queueCopy = queue2;
            if (queueCopy.empty())
            {
                cout << "<empty>";
            }
            else
            {
                while (!queueCopy.empty())
                {
                    cout << queueCopy.front() << " ";
                    queueCopy.pop();
                }
            }
            cout << endl;
            cout << "3: ";
            stack<string> stackCopy = rowOfChairs;
            if (stackCopy.empty())
            {
                cout << "<empty>";
            }
            else
            {
                while (!stackCopy.empty())
                {
                    cout << stackCopy.top() << " ";
                    stackCopy.pop();
                }
            }
            cout << endl;
        }
        else
        {
            if (info.at(1) == "1")
            {
                queue1.push(info.at(0));
            }
            else
            {
                queue2.push(info.at(0));
            }
        }
	}
}
