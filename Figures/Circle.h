#pragma once

#include "Figure.h"

class Circle : public Figure {
private:
	double radius;

public:
	Circle(double radius);
	double getRadius() const;
	double perimeter() const override;
	std::unique_ptr<Figure> clone() const override;
	std::string toString() const override;
};