#pragma once

#include "Figure.h"

class Rectangle : public Figure {
private:
	double width;
	double height;

public:
	Rectangle(double width, double height);
	double perimeter() const override;
	Figure* clone() const override;
	std::string toString() const override;
};