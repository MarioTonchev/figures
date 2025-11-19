#include <stdexcept>
#include <numbers>
#include "Circle.h"

Circle::Circle(double radius) {
	if (radius <= 0)
	{
		throw std::invalid_argument("Circle radius must be greater than zero");
	}

	if (radius > std::numeric_limits<double>::max() / (2 * std::numbers::pi))
	{
		throw std::overflow_error("Circle perimeter would overflow.");
	}

	this->radius = radius;
}

double Circle::getRadius() const {
	return radius;
}

double Circle::perimeter() const {
	return 2 * std::numbers::pi * radius;
}

std::unique_ptr<Figure> Circle::clone() const {
	return std::make_unique<Circle>(radius);
}

std::string Circle::toString() const {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2);
	oss << "circle " << radius;
	return oss.str();
}