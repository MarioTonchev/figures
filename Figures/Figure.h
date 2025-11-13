#pragma once

class Figure {
public:
	virtual double perimeter() const = 0;
	virtual ~Figure() = default;
};