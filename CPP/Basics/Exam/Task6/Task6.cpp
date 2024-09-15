#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int firstTop, secondTop, thirdTop;
    cin >> firstTop >> secondTop >> thirdTop;

    for (int i = 2; i <= firstTop; i += 2)
    {
        for (int j = 2; j <= secondTop; j++)
        {
            for (int m = 2; m <= thirdTop; m += 2)
            {
                if (j != 4 && j != 6 && j != 8 && j != 9)
                {
                    cout << i << " " << j << " " << m << endl;
                }
            }
        }
    }
}