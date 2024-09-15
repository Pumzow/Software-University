#include <iostream>

using namespace std;

void GetClosestToCenter(double x1, double y1, double x2, double y2)
{
    double result = abs(x1) + abs(y1);
    double result2 = abs(x2) + abs(y2);

    if (result < result2)
    {
        cout << "(" << x1 << ", " << y1<< ")" << endl;
    }
    else
    {
        cout << "(" << x2 << ", " << y2 << ")" << endl;
    }
}

int main()
{
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    GetClosestToCenter(x1, y1, x2, y2);
}
