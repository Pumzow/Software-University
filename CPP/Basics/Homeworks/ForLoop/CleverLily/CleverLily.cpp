#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int age;
    cin >> age;

    double washingMashinePrice;
    cin >> washingMashinePrice;

    int toyPrice;
    cin >> toyPrice;

    int moneyYears = 0;
    int toyYears = 0;
    int money = 0;
    int saveMoney = 0;

    for (int i = 1; i <= age; i++) {
        if (i % 2 == 0) {
            moneyYears++;
            money = moneyYears * 10;
            saveMoney = saveMoney + money;
        }
        else {
            toyYears++;
        }
    }
    money = saveMoney - moneyYears + (toyYears * toyPrice);

    double diff = abs(washingMashinePrice - money);
    cout.setf(ios::fixed);
    cout.precision(2);
    if (money >= washingMashinePrice) {
        cout << "Yes! " << diff;
    }
    else {
        cout << "No! " << diff;
    }

    return 0;
}