#pragma once

#include "Figure.h"

class Triangle : public Figure {
private:
	double a;
	double b;
	double c;

public:
	Triangle(double a, double b, double c);
	double perimeter() const override;
	Figure* clone() const override;
	std::string toString() const override;
};