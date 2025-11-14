#pragma once

#include "FigureFactory.h"
#include "StringToFigure.h"

class StreamFigureFactory : public FigureFactory {
private:
	std::istream& in;
	StringToFigure converter;

public:
	StreamFigureFactory(std::istream& in);
	std::unique_ptr<Figure> create() override;
};