#pragma once

#include <memory>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

class FigureFactory {
public:
	virtual std::unique_ptr<Figure> create() = 0;
	virtual ~FigureFactory() = default;
};