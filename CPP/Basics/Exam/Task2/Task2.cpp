#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int daysOff, foodLeft;
	double firstDeerFoodPerDay, secondDeerFoodPerDay, thirdDeerFoodPerDay;

	cin >> daysOff >> foodLeft >> firstDeerFoodPerDay >> secondDeerFoodPerDay >> thirdDeerFoodPerDay;

	double firstTotalFood = daysOff * firstDeerFoodPerDay;
	double secondTotalFood = daysOff * secondDeerFoodPerDay;
	double thirdTotalFood = daysOff * thirdDeerFoodPerDay;
	double totalFoodNeeded = firstTotalFood + secondTotalFood + thirdTotalFood;

	if (totalFoodNeeded <= foodLeft)
	{
		cout << floor(foodLeft - totalFoodNeeded) << " kilos of food left." << endl;
	}
	else
	{
		cout << ceil(totalFoodNeeded - foodLeft) << " more kilos of food are needed." << endl;
	}
}