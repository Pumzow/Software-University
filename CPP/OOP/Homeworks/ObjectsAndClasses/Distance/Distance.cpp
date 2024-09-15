#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Sentence
{
	int xPosition, yPosition;
	public:
	Sentence(int x, int y)
	{
		xPosition = x;
		yPosition = y;
	}

	double getDistanceToPoint(Sentence otherPoint)
	{
		return sqrt(pow(otherPoint.xPosition - xPosition, 2) + pow(otherPoint.yPosition - yPosition, 2));
	}
};

int main()
{

	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;

	Sentence point1(x, y);
	Sentence point2(x1, y1);

	cout.setf(ios::fixed);
	cout.precision(3);
	cout << point1.getDistanceToPoint(point2) << endl;
}
