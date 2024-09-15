#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	double magneziumPercent;
	cin >> magneziumPercent;
	double magneziumProtein;
	cin >> magneziumProtein;
	double magneziumVuglehidrati;
	cin >> magneziumVuglehidrati;
	double totalCalories;
	cin >> totalCalories;
	int waterPercent;
	cin >> waterPercent;

	double gramsMaznini = totalCalories * (magneziumPercent*.01) / 9;
	double gramsProtein = totalCalories * (magneziumProtein *.01) / 4;
	double gramsVuglehidrati = totalCalories * (magneziumVuglehidrati *.01) / 4;
	double teglo = gramsMaznini + gramsProtein + gramsVuglehidrati;
	double caloriesOnGram = totalCalories / teglo;
	double percent = 100 - waterPercent;
	double result = caloriesOnGram * (percent * .01);

	cout << fixed << setprecision(4) << result << endl;
}