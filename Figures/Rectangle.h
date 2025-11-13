#pragma once

#include "Figure.h"

class Rectangle : Figure {
private:
	double width;
	double height;

public:
	Rectangle(double width, double height);
	double perimeter() const override;
};