#pragma once

#include "Figure.h"

class Triangle : public Figure {
private:
	double a;
	double b;
	double c;

public:
	Triangle(double a, double b, double c);
	double getA() const;
	double getB() const;
	double getC() const;
	double perimeter() const override;
	std::unique_ptr<Figure> clone() const override;
	std::string toString() const override;
};