#pragma once

#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"

class FigureFactorySelector {
public:
	static std::unique_ptr<FigureFactory> createFactory(std::string& type, std::istream* stream = nullptr);
};