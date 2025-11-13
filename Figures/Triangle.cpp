#include <stdexcept>
#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0)
	{
		throw std::invalid_argument("Triangle sides must be greater than zero");
	}

	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw std::invalid_argument("Triangle inequality");
	}

	if (a > std::numeric_limits<double>::max() - b - c)
	{
		throw std::overflow_error("Triangle perimeter will overflow");
	}

	this->a = a;
	this->b = b;
	this->c = c;
}

double Triangle::perimeter() const {
	return a + b + c;
}
