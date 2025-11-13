#pragma once

#include <string>

class Figure {
public:
	virtual double perimeter() const = 0;
	virtual std::string toString() const = 0;
	virtual Figure* clone() const = 0;
	virtual ~Figure() = default;
};