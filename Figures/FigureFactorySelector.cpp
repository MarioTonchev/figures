#include <iostream>
#include "FigureFactorySelector.h"

std::unique_ptr<FigureFactory> FigureFactorySelector::createFactory(std::string& type, std::istream* stream) {
	if (type == "random")
	{
		return std::make_unique<RandomFigureFactory>();
	}
	else if (type == "console")
	{
		return std::make_unique<StreamFigureFactory>(std::cin);
	}
	else if (type == "file")
	{
		return std::make_unique<StreamFigureFactory>(*stream);
	}
	else
	{
		throw std::invalid_argument("Factory type is not supported");
	}
}