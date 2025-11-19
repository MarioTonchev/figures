#include "StringToFigure.h"

std::unique_ptr<Figure> StringToFigure::createFigureFrom(std::string& input) {
	std::stringstream ss(input);

	std::string type;
	ss >> type;

	if (type.empty())
	{
		throw std::invalid_argument("Empty figure string");
	}

	return FigureRegistry::getInstance().create(type, ss);
}