#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int totalMetersTraveled = 5364;
	int daysTraveled = 1;
	while (true)
	{
		string input;
		cin >> input;

		if (input == "END") break;
		int metersTraveled;
		cin >> metersTraveled;
		if (input == "Yes")
		{
			daysTraveled++;
			if (daysTraveled > 5) break;
		}

		totalMetersTraveled += metersTraveled;
		if (totalMetersTraveled >= 8848) break;
	}

	if (totalMetersTraveled >= 8848)
	{
		cout << "Goal reached for " << daysTraveled << " days!" << endl;
	}
	else
	{
		cout << "Failed!" << endl;
		cout << totalMetersTraveled << endl;
	}
}