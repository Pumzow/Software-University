#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int finalNumber;
    if (a > b)
        finalNumber = b;
    else
        finalNumber = a;

    int gcd = 0;
    for (int cnt = 1; cnt <= finalNumber; cnt++)
    {
        if ((a % cnt == 0) && (b % cnt == 0)) 
        {
            gcd = cnt;
        }
    }

    cout << gcd << endl;
}
