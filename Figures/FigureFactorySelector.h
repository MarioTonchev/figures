#pragma once

#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"

class FigureFactorySelector {
public:
	static FigureFactory* createFactory(std::string& type, std::istream* in = nullptr);
};