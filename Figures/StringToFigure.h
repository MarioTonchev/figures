#pragma once

#include <memory>
#include <sstream>
#include "FigureRegistry.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

class StringToFigure {
public:
	std::unique_ptr<Figure> createFigureFrom(std::string& input);
};