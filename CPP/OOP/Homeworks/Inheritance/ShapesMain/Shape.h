#pragma once
#include "Vector2D.h"

class Shape
{
public:
	Vector2D center;
	double area;
	Shape() : center(0, 0), area(0) {};
	Shape(Vector2D center) : center(center) {};

	Vector2D getCenter()
	{
		return center;
	}

	double getArea()
	{
		return area;
	}
};
