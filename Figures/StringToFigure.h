#pragma once

#include <sstream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

class StringToFigure {
public:
	Figure* createFigureFrom(std::string input);
};