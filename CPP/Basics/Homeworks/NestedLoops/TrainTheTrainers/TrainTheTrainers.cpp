#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int k = 0;
	double totalGrade = 0;
	while (true)
	{
		string input;
		cin.ignore();
		getline(cin, input);

		if (input == "Finish") break;

		double currentTotalGrade = 0;
		for (int i = 0; i < n; i++)
		{
			double grade;
			cin >> grade;

			currentTotalGrade += grade;
			totalGrade += grade;
			k++;
		}

		cout << fixed<< setprecision(2) << input << " - " << currentTotalGrade / n << "." << endl;
	}

	cout << fixed << setprecision(2) << "Student's final assessment is " << totalGrade / k << "." << endl;
}
