#include "StringToFigure.h"

Figure* StringToFigure::createFigureFrom(std::string input) {
	std::stringstream ss(input);

	std::string type;
	ss >> type;

	if (type == "triangle")
	{
		double a, b, c;

		if (!(ss >> a >> b >> c))
		{
			throw std::invalid_argument("Triangle requires 3 sides");
		}

		return new Triangle(a, b, c);
	}
	else if (type == "rectangle")
	{
		double width, height;
		
		if (!(ss >> width >> height))
		{
			throw std::invalid_argument("Rectangle requires width and height");
		}

		return new Rectangle(width, height);
	}
	else if (type == "circle")
	{
		double radius;
		
		if (!(ss >> radius))
		{
			throw std::invalid_argument("Circle requires radius");
		}

		return new Circle(radius);
	}
	else
	{
		throw std::invalid_argument("Figure is not supported");
	}
}