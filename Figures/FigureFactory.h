#pragma once

#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

class FigureFactory {
public:
	virtual Figure* create() = 0;
	virtual ~FigureFactory() = default;
};