#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int numTour;
    int startPoints;
    cin >> numTour >> startPoints;

    double sumW = 0;
    double sumF = 0;
    double sumSf = 0;
    double numW = 0;

    for (int i = 1; i <= numTour; i++)
    {
        string lvl;
        cin >> lvl;

        if (lvl == "W")
        {
            sumW = sumW + 2000;
            numW++;
        }
        else if (lvl == "F")
        {
            sumF += 1200;
        }
        else if (lvl == "SF")
        {
            sumSf += 720;
        }

    }
    double prWins = numW / numTour * 100;
    double sumFromTour = sumSf + sumW + sumF;
    double allPoints = sumSf + sumW + sumF + startPoints;
    double averagePoints = floor(sumFromTour / numTour);

    cout << "Final points: "<< allPoints << endl;
    cout << "Average points: "<< averagePoints << endl;
    cout << fixed << setprecision(2) << prWins << "%" << endl;
}
