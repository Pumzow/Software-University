#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double n;
    cin >> n;

    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    int p5 = 0;
    double p1sum = 0;
    double p2sum = 0;
    double p3sum = 0;
    double p4sum = 0;
    double p5sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int numbers;
        cin >> numbers;

        if (numbers < 200)
        {
            p1++;

        }
        else if (numbers >= 200 && numbers < 400)
        {
            p2++;

        }
        else if (numbers >= 400 && numbers < 600)
        {
            p3++;

        }
        else if (numbers >= 600 && numbers < 800)
        {
            p4++;

        }
        else if (numbers >= 800)
        {
            p5++;

        }
    }
    p1sum += (p1 / n) * 100;
    p2sum += (p2 / n) * 100;
    p3sum += p3 / n * 100;
    p4sum += p4 / n * 100;
    p5sum += p5 / n * 100;

    cout << fixed << setprecision(2) << p1sum << "%" << endl;
    cout << fixed << setprecision(2) << p2sum << "%" << endl;
    cout << fixed << setprecision(2) << p3sum << "%" << endl;
    cout << fixed << setprecision(2) << p4sum << "%" << endl;
    cout << fixed << setprecision(2) << p5sum << "%" << endl;
}
