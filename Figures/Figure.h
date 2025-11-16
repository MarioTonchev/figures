#pragma once

#include <string>
#include <memory>
#include <sstream>
#include <iomanip>

class Figure {
public:
	virtual double perimeter() const = 0;
	virtual std::string toString() const = 0;
	virtual std::unique_ptr<Figure> clone() const = 0;
	virtual ~Figure() = default;
};