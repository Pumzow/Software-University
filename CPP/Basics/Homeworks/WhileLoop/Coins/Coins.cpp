#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double _change;
    cin >> _change;
    double _levs = floor(_change);
    double _pennies = round((_change - _levs) * 100);
    double _coins = 0;

    while (_levs > 0)
    {
        if (_levs >= 2)
        {
            _coins += 1;
            _levs -= 2;
        }
        else if (_levs >= 1)
        {
            _coins += 1;
            _levs -= 1;
        }
    }
    while (_pennies > 0)
    {
        if (_pennies >= 50)
        {
            _coins += 1;
            _pennies -= 50;
        }
        else if (_pennies >= 20)
        {
            _coins += 1;
            _pennies -= 20;
        }
        else if (_pennies >= 10)
        {
            _coins += 1;
            _pennies -= 10;
        }
        else if (_pennies >= 05)
        {
            _coins += 1;
            _pennies -= 05;
        }
        else if (_pennies >= 02)
        {
            _coins += 1;
            _pennies -= 02;
        }
        else if (_pennies >= 01)
        {
            _coins += 1;
            _pennies -= 01;
            break;
        }
        else
        {
            break;
        }
    }
    cout << _coins;
}
