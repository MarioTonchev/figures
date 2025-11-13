#pragma once

#include "Figure.h"

class Triangle : Figure {
private:
	double a;
	double b;
	double c;

public:
	Triangle(double a, double b, double c);
	double perimeter() const override;
};