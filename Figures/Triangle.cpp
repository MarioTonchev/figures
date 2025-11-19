#include <stdexcept>
#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0)
	{
		throw std::invalid_argument("Triangle sides must be greater than zero");
	}

	if (a > std::numeric_limits<double>::max() - b - c)
	{
		throw std::overflow_error("Triangle perimeter will overflow");
	}

	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw std::invalid_argument("Triangle inequality");
	}

	this->a = a;
	this->b = b;
	this->c = c;
}

double Triangle::getA() const {
	return a;
}

double Triangle::getB() const {
	return b;
}

double Triangle::getC() const {
	return c;
}

double Triangle::perimeter() const {
	return a + b + c;
}

std::unique_ptr<Figure> Triangle::clone() const {
	return std::make_unique<Triangle>(a, b, c);
}

std::string Triangle::toString() const {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2);
	oss << "triangle " << a << " " << b << " " << c;
	return oss.str();
}