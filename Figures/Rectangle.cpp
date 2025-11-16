#include <stdexcept>
#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) {
	if (width <= 0 || height <= 0)
	{
		throw std::invalid_argument("Rectangle sides must be greater than zero");
	}

	if (width > (std::numeric_limits<double>::max() / 2) - height)
	{
		throw std::overflow_error("Rectangle perimeter will overflow");
	}

	this->width = width;
	this->height = height;
}

double Rectangle::perimeter() const {
	return 2 * (width + height);
}

std::unique_ptr<Figure> Rectangle::clone() const {
	return std::make_unique<Rectangle>(width, height);
}

std::string Rectangle::toString() const {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2);
	oss << "rectangle " << width << " " << height;
	return oss.str();
}